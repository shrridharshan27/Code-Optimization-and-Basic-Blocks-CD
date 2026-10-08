/**
 * ============================================================================
 * Course: Compiler Design Laboratory (BCSE306L)
 * Experiment 12: Basic Blocks, Control Flow Graph (CFG) & Peephole Optimization
 * Author: Shrri Dharshan D R (Reg No: 23BPS1090)
 * Slot: L23+L24
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void analyze_basic_blocks(void) {
    printf("============================================================\n");
    printf("       PART 1: LEADER IDENTIFICATION & BASIC BLOCKS         \n");
    printf("============================================================\n\n");

    printf("Original Intermediate Code (7 Statements):\n");
    printf("  1. a = b + c\n");
    printf("  2. d = a - e\n");
    printf("  3. if d > 0 goto L1\n");
    printf("  4. f = d * 2\n");
    printf("  5. goto L2\n");
    printf("  6. L1: f = d / 2\n");
    printf("  7. L2: g = f + 1\n\n");

    printf("Leader Identification Rules Applied:\n");
    printf("  Rule 1 (First statement): Statement 1 is a Leader.\n");
    printf("  Rule 2 (Target of jump): Statement 6 (L1) and Statement 7 (L2) are Leaders.\n");
    printf("  Rule 3 (Immediately follows jump): Statement 4 (follows line 3) is a Leader.\n\n");

    printf("Identified Leaders: { Statement 1, Statement 4, Statement 6, Statement 7 }\n\n");

    printf("Partitioned Basic Blocks:\n");
    printf("------------------------------------------------------------\n");
    printf("  Block B1 [Lines 1-3]:\n");
    printf("      a = b + c\n");
    printf("      d = a - e\n");
    printf("      if d > 0 goto L1\n\n");

    printf("  Block B2 [Lines 4-5]:\n");
    printf("      f = d * 2\n");
    printf("      goto L2\n\n");

    printf("  Block B3 [Line 6]:\n");
    printf("      L1: f = d / 2\n\n");

    printf("  Block B4 [Line 7]:\n");
    printf("      L2: g = f + 1\n\n");

    printf("Control Flow Graph (CFG) Structure:\n");
    printf("------------------------------------------------------------\n");
    printf("               +------------+\n");
    printf("               |  Block B1  |\n");
    printf("               +------------+\n");
    printf("                 /        \\\n");
    printf("      (False)   /          \\  (True: d > 0)\n");
    printf("               v            v\n");
    printf("         +------------+  +------------+\n");
    printf("         |  Block B2  |  |  Block B3  |\n");
    printf("         +------------+  +------------+\n");
    printf("                \\           /\n");
    printf("                 \\         /\n");
    printf("                  v       v\n");
    printf("               +------------+\n");
    printf("               |  Block B4  |\n");
    printf("               +------------+\n\n");
}

void apply_peephole_optimization(void) {
    printf("============================================================\n");
    printf("       PART 2: PEEPHOLE OPTIMIZATION & COPY PROPAGATION     \n");
    printf("============================================================\n\n");

    int b = 10;

    /* Original unoptimized operations */
    int a_orig = b * 1;
    int c_orig = a_orig + 0;
    int d_orig = c_orig * 2;
    int e_orig = d_orig / 1;

    printf("Original Intermediate Statements:\n");
    printf("  1. a = b * 1     -> %d\n", a_orig);
    printf("  2. c = a + 0     -> %d\n", c_orig);
    printf("  3. d = c * 2     -> %d\n", d_orig);
    printf("  4. e = d / 1     -> %d\n\n", e_orig);

    printf("Peephole Optimization Rules Applied:\n");
    printf("  Rule 1 (Identity Multiplication): x * 1 = x  ==> a = b\n");
    printf("  Rule 2 (Identity Addition)      : x + 0 = x  ==> c = a\n");
    printf("  Rule 3 (Strength Reduction)     : x * 2 = x << 1 ==> d = c << 1\n");
    printf("  Rule 4 (Identity Division)      : x / 1 = x  ==> e = d\n\n");

    int a_opt = b;
    int c_opt = a_opt;
    int d_opt = c_opt << 1;
    int e_opt = d_opt;

    printf("Optimized Code:\n");
    printf("  a = b        = %d\n", a_opt);
    printf("  c = a        = %d\n", c_opt);
    printf("  d = c << 1   = %d\n", d_opt);
    printf("  e = d        = %d\n\n", e_opt);

    /* Copy propagation */
    int e_propagated = b << 1;
    printf("After Copy Propagation & Dead Code Elimination:\n");
    printf("  e = b << 1   = %d  (Reduced entire 4-instruction block to 1 single shift!)\n\n", e_propagated);
}

int main(void) {
    analyze_basic_blocks();
    apply_peephole_optimization();
    return 0;
}
