#!/usr/bin/env bash
find src -type f -name '*.[ch]pp' -exec clang-format -style=file  -i {} \;
