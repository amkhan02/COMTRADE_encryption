Package: gmp:x64-windows@6.3.0#1

**Host Environment**

- Host: x64-windows
- Compiler: MSVC 19.41.34123.0
-    vcpkg-tool version: 2024-10-18-e392d7347fe72dff56e7857f7571c22301237ae6
    vcpkg-scripts version: 2a3138723 2024-11-04 (4 hours ago)

**To Reproduce**

`vcpkg install `

**Failure logs**

```
-- Using cached gmp-6.3.0.tar.xz.
-- Cleaning sources at C:/Users/Ameen/OneDrive - Georgia Institute of Technology/Documents/School/power/vcpkg/buildtrees/gmp/src/v6.3.0-036e54f1a3.clean. Use --editable to skip cleaning for the packages you specify.
-- Extracting source C:/Users/Ameen/OneDrive - Georgia Institute of Technology/Documents/School/power/vcpkg/downloads/gmp-6.3.0.tar.xz
-- Applying patch asmflags.patch
-- Applying patch cross-tools.patch
-- Applying patch subdirs.patch
-- Applying patch msvc_symbol.patch
-- Applying patch arm64-coff.patch
-- Using source at C:/Users/Ameen/OneDrive - Georgia Institute of Technology/Documents/School/power/vcpkg/buildtrees/gmp/src/v6.3.0-036e54f1a3.clean
-- Found external ninja('1.11.0').
-- Getting CMake variables for x64-windows
-- Using cached LLVM-15.0.6-win64.7z.exe.
CMake Error at scripts/cmake/vcpkg_extract_archive.cmake:19 (message):
  C:/Users/Ameen/OneDrive - Georgia Institute of
  Technology/Documents/School/power/vcpkg/downloads/tools/clang/clang-15.0.6
  was an extraction target, but it already exists.
Call Stack (most recent call first):
  scripts/cmake/vcpkg_find_acquire_program.cmake:212 (vcpkg_extract_archive)
  C:/Users/Ameen/AppData/Local/vcpkg/registries/git-trees/0634ea068717e4b97b9a9d767d70179b909657b6/portfile.cmake:55 (vcpkg_find_acquire_program)
  scripts/ports.cmake:192 (include)



```

**Additional context**

<details><summary>vcpkg.json</summary>

```
{
  "dependencies": [
    "gmp"
  ]
}

```
</details>
