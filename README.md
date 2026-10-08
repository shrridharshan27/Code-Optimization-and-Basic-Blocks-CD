# Basic Blocks, Control Flow Graphs (CFG) & Peephole Optimization

[![Language](https://img.shields.io/badge/Language-C99%20%2F%20C11-00599C.svg?logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Optimizer](https://img.shields.io/badge/Optimizer-Peephole%20%7C%20CFG-green.svg)](https://gcc.gnu.org/)
[![Course](https://img.shields.io/badge/Course-BCSE306L%20Compiler%20Design-red.svg)](https://vit.ac.in)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Author Information
- **Author:** Shrri Dharshan D R
- **GitHub:** [@shrridharshan27](https://github.com/shrridharshan27)
- **Registration Number:** `23BPS1090`
- **Course:** Compiler Design Laboratory (`BCSE306L`)
- **Lab Slot:** `L23+L24`

---

## Overview
This repository implements core intermediate code analysis and code optimization techniques:
1. **Leader Identification**: Identifies entry points of basic blocks according to formal compiler rules.
2. **Basic Block Partitioning**: Groups sequential instructions with single-entry and single-exit semantics.
3. **Control Flow Graph (CFG)**: Models flow transfer between basic blocks with branching edges.
4. **Peephole Optimization**: Scans a small sliding window of intermediate code to apply:
   - Algebraic identity simplification ($x * 1 	o x$, $x + 0 	o x$, $x / 1 	o x$).
   - Strength reduction ($x * 2 	o x \ll 1$).
   - Copy propagation and dead-code elimination.

---

## Compilation & Execution
```bash
# Compile and run with GCC
gcc -std=c99 -Wall -Wextra src/basic_blocks_and_optimization.c -o build/opt_cfg
./build/opt_cfg
```

---

## License
MIT License - see [LICENSE](LICENSE) for details.
