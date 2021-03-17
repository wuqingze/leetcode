### 71. Simplify Path
<span style="color:rgb(239, 108, 0)">Medium</span> &nbsp;**favorable:** 275 &nbsp; **unfavorable:** 87

Given a string `path`, which is an **absolute path** (starting with a slash `'/'`) to a file or directory in a Unix-style file system, convert it to the simplified **canonical path**.

In a Unix-style file system, a period `'.'` refers to the current directory, a double period `'..'` refers to the directory up a level, and any multiple consecutive slashes (i.e. `'//'`) are treated as a single slash `'/'`. For this problem, any other format of periods such as `'...'` are treated as file/directory names.

The `canonical path` should have the following format:
- The path starts with a single slash `'/'`.
- Any two directories are separated by a single slash `'/'`.
- The path does not end with a trailing `'/'`.
- The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period `'.'` or double period `'..'`) 

Return the simplified **canonical path**.

#### Example 1:
```
<span stype="font-weight:bold">Input:</span> path = "/home/"
<span stype="font-weight:bold">Output:</span> "/home"
<span stype="font-weight:bold">Explanation:</span> Note that there is no trailing slash after the last directory name.
```

#### Example 2:
```
<span stype="font-weight:bold">Input:</span> path = "/../"
<span stype="font-weight:bold">Output:</span> "/"
<span stype="font-weight:bold">Explanation:</span> Going one level up from the root directory is a no-op, as the root level is the highest 
level you can go.
```

#### Example 3:
```
<span stype="font-weight:bold">Input:</span> path = "/home//foo/"
<span stype="font-weight:bold">Output:</span> "/home/foo"
<span stype="font-weight:bold">Explanation:</span> In the canonical path, multiple consecutive slashes are replaced by a single one.
```

#### Example 4:
```
<span stype="font-weight:bold">Input:</span> path = "/a/./b/../../c/"
<span stype="font-weight:bold">Output:</span> "/c"
``` 

#### Constraints:
- 1 <= path.length <= 3000
- path consists of English letters, digits, period '.', slash '/' or '_'.
- path is a valid absolute Unix path.
