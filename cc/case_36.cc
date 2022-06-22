

#include <stdio.h>
#include "ap_fixed.h"

void case_36(
    ap_int<16> in_data[12],
    ap_int<16> out_data[6]
)
{

#pragma HLS array_partition variable=in_data complete
#pragma HLS array_partition variable=out_data complete

    

ap_int<6> in1;
in1.range(5, 0) = in_data[0].range(5, 0);
ap_int<5> in2;
in2.range(4, 0) = in_data[1].range(4, 0);
ap_int<5> in3;
in3.range(4, 0) = in_data[2].range(4, 0);
ap_int<10> in4;
in4.range(9, 0) = in_data[3].range(9, 0);
ap_int<8> in5;
in5.range(7, 0) = in_data[4].range(7, 0);
ap_int<9> in6;
in6.range(8, 0) = in_data[5].range(8, 0);
ap_int<3> in7;
in7.range(2, 0) = in_data[6].range(2, 0);
ap_int<9> in8;
in8.range(8, 0) = in_data[7].range(8, 0);
ap_int<7> in9;
in9.range(6, 0) = in_data[8].range(6, 0);
ap_int<15> in10;
in10.range(14, 0) = in_data[9].range(14, 0);
ap_int<8> in11;
in11.range(7, 0) = in_data[10].range(7, 0);
ap_int<3> in12;
in12.range(2, 0) = in_data[11].range(2, 0);

ap_int<7> m13;
ap_int<13> m14;
ap_int<10> m15;
ap_int<5> m16;
ap_int<8> m17;
ap_int<10> m18;
ap_int<9> m19;
ap_int<9> m20;
ap_int<9> m21;
ap_int<15> m22;
ap_int<11> m23;
ap_int<12> m24;
ap_int<5> m25;
ap_int<10> m26;
ap_int<11> m27;
ap_int<11> m28;
ap_int<14> m29;
ap_int<10> m30;
ap_int<6> m31;
ap_int<3> m32;
ap_int<13> m33;
ap_int<9> m34;
ap_int<10> m35;
ap_int<5> m36;
ap_int<4> m37;
ap_int<10> m38;
ap_int<7> m39;
ap_int<9> m40;
ap_int<6> m41;
ap_int<11> m42;
ap_int<12> m43;
ap_int<13> m44;
ap_int<13> m45;
ap_int<15> m46;
ap_int<10> m47;
ap_int<9> m48;
ap_int<11> m49;
ap_int<13> m50;
ap_int<16> m51;
ap_int<4> m52;
ap_int<13> m53;
ap_int<10> m54;
ap_int<11> m55;
ap_int<12> m56;
ap_int<11> m57;
ap_int<15> m58;
ap_int<6> m59;

m13 = in9 * in7;
m14 = in9 + in10;
m15 = m14 * m14;
m16 = in4 + m13;
m17 = in7 * in6;
m18 = m15 * in11;
m19 = in12 * m14;
m20 = in10 * m18;
m21 = m17 * in9;
m22 = in10 * m15;
m23 = in11 * m22;
m24 = m19 * m23;
m25 = m22 + m16;
m26 = m24 * m17;
m27 = m23 + m21;
m28 = m16 + m27;
m29 = m20 * m25;
m30 = m26 + m28;
m31 = m19 * m28;
m32 = m31 * m25;
m33 = m25 * m21;
m34 = m22 + m22;
m35 = m33 * m26;
m36 = m28 * m30;
m37 = m36 * m32;
m38 = m37 * m27;
m39 = m37 * m29;
m40 = m34 * m29;
m41 = m40 * m35;
m42 = m30 + m37;
m43 = m42 * m36;
m44 = m43 * m33;
m45 = m39 * m41;
m46 = m44 * m37;
m47 = m40 * m44;
m48 = m45 + m45;
m49 = m38 + m37;
m50 = m39 * m39;
m51 = m44 * m41;
m52 = m41 * m42;
m53 = m47 + m48;
m54 = m47 + m44;
m55 = m53 * m49;
m56 = m51 * m54;
m57 = m45 * m56;
m58 = m46 + m48;
m59 = m53 * m54;

out_data[0] = m50;
out_data[1] = m52;
out_data[2] = m55;
out_data[3] = m57;
out_data[4] = m58;
out_data[5] = m59;


}
    