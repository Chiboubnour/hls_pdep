
//              Copyright Catch2 Authors
// Distributed under the Boost Software License, Version 1.0.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.boost.org/LICENSE_1_0.txt)

// SPDX-License-Identifier: BSL-1.0

// 010-TestCase.cpp
// And write tests in the same file:
#include <catch2/catch_test_macros.hpp>


#include "./pdep_u64_ref.hpp"
#include "../src/pdep_u64.hpp"

TEST_CASE( "pdep_c", "[pdep:c]" ) {

    ap_uint<64> val  = 0x0000000000000200;  
    ap_uint<64> mask = 0x51aff40c39426f8c;  
    ap_uint<64> expected_result =  0x0000000000020000;  
    REQUIRE(pdep_u64_arm(val, mask) == expected_result);
    
}

TEST_CASE( "pdep_hls", "[pdep:hls]" ) {

    ap_uint<64> val  = 0x0000000000000200;  
    ap_uint<64> mask = 0x51aff40c39426f8c;  
    ap_uint<64> expected_result =  0x0000000000020000;  
    REQUIRE(pdep_hls(val, mask) == expected_result); 
   
}



