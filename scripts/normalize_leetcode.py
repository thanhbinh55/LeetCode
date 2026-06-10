#!/usr/bin/env python3
from __future__ import annotations

import re
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SOURCE_EXTENSIONS = {
    "c",
    "cpp",
    "cs",
    "go",
    "java",
    "js",
    "kt",
    "php",
    "py",
    "rb",
    "rs",
    "scala",
    "swift",
    "ts",
}


def slug_to_title(slug: str) -> str:
    return " ".join(part.capitalize() for part in slug.split("-") if part)


def normalize_slug(raw: str) -> str:
    slug = raw.lower().replace("_", "-").replace(".", "-").replace(" ", "-")
    slug = re.sub(r"[^a-z0-9-]", "", slug)
    slug = re.sub(r"-+", "-", slug).strip("-")
    return slug


def parse_solution_name(path: Path) -> tuple[int, str, str] | None:
    if path.suffix[1:] not in SOURCE_EXTENSIONS:
        return None

    stem = path.stem
    match = re.match(r"^(\d+)[.-](.+)$", stem)
    if not match:
        return None

    problem_id = int(match.group(1))
    slug = normalize_slug(match.group(2))
    if not slug:
        return None

    return problem_id, slug, path.suffix[1:]


def readme_template(problem_id: int, slug: str) -> str:
    title = slug_to_title(slug)
    return f"""# {problem_id}. {title}

**Link:** https://leetcode.com/problems/{slug}/

## Summary

TODO: Add a short problem summary.

## Approach

TODO: Add the main idea after solving.

## Complexity

- Time: `TODO`
- Space: `TODO`
"""


def normalize_file(source: Path) -> bool:
    parsed = parse_solution_name(source)
    if parsed is None:
        return False

    problem_id, slug, ext = parsed
    padded = f"{problem_id:04d}"
    target_dir = ROOT / f"{padded}-{slug}"
    target_file = target_dir / f"{padded}-{slug}.{ext}"

    if source == target_file:
        return False

    if target_file.exists():
        raise FileExistsError(f"Target already exists: {target_file}")

    target_dir.mkdir(exist_ok=True)
    source.rename(target_file)

    readme = target_dir / "README.md"
    if not readme.exists():
        readme.write_text(readme_template(problem_id, slug), encoding="utf-8")

    if source.parent != ROOT and source.parent.exists():
        try:
            source.parent.rmdir()
        except OSError:
            pass

    print(f"Moved {source.relative_to(ROOT)} -> {target_file.relative_to(ROOT)}")
    return True


def main() -> None:
    changed = False

    for path in sorted(ROOT.iterdir()):
        if path.is_file():
            changed = normalize_file(path) or changed
        elif path.is_dir() and not path.name.startswith((".", "000")):
            for child in sorted(path.iterdir()):
                if child.is_file():
                    changed = normalize_file(child) or changed

    if not changed:
        print("No LeetCode files needed normalization.")


if __name__ == "__main__":
    main()
