

#include <stdio.h>
#include "ap_fixed.h"

void case_17(
    ap_int<16> in_data[11],
    ap_int<16> out_data[7]
)
{

#pragma HLS array_partition variable=in_data complete
#pragma HLS array_partition variable=out_data complete

    

ap_int<2> in1;
in1.range(1, 0) = in_data[0].range(1, 0);
ap_int<12> in2;
in2.range(11, 0) = in_data[1].range(11, 0);
ap_int<4> in3;
in3.range(3, 0) = in_data[2].range(3, 0);
ap_int<2> in4;
in4.range(1, 0) = in_data[3].range(1, 0);
ap_int<8> in5;
in5.range(7, 0) = in_data[4].range(7, 0);
ap_int<5> in6;
in6.range(4, 0) = in_data[5].range(4, 0);
ap_int<7> in7;
in7.range(6, 0) = in_data[6].range(6, 0);
ap_int<3> in8;
in8.range(2, 0) = in_data[7].range(2, 0);
ap_int<10> in9;
in9.range(9, 0) = in_data[8].range(9, 0);
ap_int<11> in10;
in10.range(10, 0) = in_data[9].range(10, 0);
ap_int<5> in11;
in11.range(4, 0) = in_data[10].range(4, 0);

ap_int<10> m12;
ap_int<8> m13;
ap_int<10> m14;
ap_int<8> m15;
ap_int<6> m16;
ap_int<4> m17;
ap_int<7> m18;
ap_int<3> m19;
ap_int<8> m20;
ap_int<5> m21;
ap_int<8> m22;
ap_int<13> m23;
ap_int<8> m24;
ap_int<4> m25;
ap_int<2> m26;
ap_int<4> m27;
ap_int<14> m28;
ap_int<10> m29;
ap_int<4> m30;
ap_int<4> m31;
ap_int<9> m32;
ap_int<8> m33;
ap_int<6> m34;
ap_int<3> m35;

m12 = in5 * in8;
m13 = in8 * in6;
m14 = in10 * in4;
m15 = in7 * in4;
m16 = m13 + in11;
m17 = in10 * m16;
m18 = m13 + in9;
m19 = in10 * m17;
m20 = in10 * in9;
m21 = m15 * m15;
m22 = m12 * m13;
m23 = m18 * m15;
m24 = m19 + m14;
m25 = m19 * m23;
m26 = m25 * m18;
m27 = m24 * m19;
m28 = m23 + m18;
m29 = m18 + m18;
m30 = m25 * m25;
m31 = m25 * m22;
m32 = m27 + m23;
m33 = m24 * m30;
m34 = m26 * m33;
m35 = m27 * m32;

out_data[0] = m20;
out_data[1] = m21;
out_data[2] = m28;
out_data[3] = m29;
out_data[4] = m31;
out_data[5] = m34;
out_data[6] = m35;


}
    