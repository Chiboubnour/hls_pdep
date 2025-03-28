#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ap_int.h>


ap_uint<64> pdep_hls(const ap_uint<64> val, ap_uint<64> mask) {
    int pos = 63 - __builtin_clz(mask); // rank;

    ap_uint<1> val_bit = val[0];

    ap_uint<64> res = val_bit << pos;

    ap_uint<7> count[64]; // array to store counts

    // Calcul des counts
    count[0] = mask[0];
    for (int i = 1; i < 64; i++) {
       #pragma HLS UNROLL

        count[i] = count[i - 1] + mask[i];
    }

    ap_uint<64> result = 0; // Variable pour stocker le résultat

    result[0] = (count[0] == pos);
    for (int i = 1; i < 64; i++) {
       #pragma HLS UNROLL

        if ((count[i] == pos) && (count[i - 1] != pos)) {
            result[i] = 1;
        } else {
            result[i] = 0;
        }
    }

    return result;
}








