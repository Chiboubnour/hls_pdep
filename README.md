## PDEP — Parallel Bits Deposit

The PDEP (Parallel Deposit) instruction is a bitwise operation that transfers the low-order bits from a source operand into a destination operand at the positions specified by a mask. PDEP takes the low bits from the first source operand and deposits them in the destination operand at the corresponding bit locations that are set in the second source operand (mask). All other bits (bits not set in mask) in the destination are set to zero.

## Repository Content

This repository includes a C implementation (`pdep_u64_arm`) and an optimized version for FPGA (`pdep_hls`) using Vitis HLS.



