

#include <stdio.h>
#include "ap_fixed.h"

void case_15(
    ap_int<16> in_data[12],
    ap_int<16> out_data[10]
)
{

#pragma HLS array_partition variable=in_data complete
#pragma HLS array_partition variable=out_data complete

    

ap_int<14> in1;
in1.range(13, 0) = in_data[0].range(13, 0);
ap_int<15> in2;
in2.range(14, 0) = in_data[1].range(14, 0);
ap_int<9> in3;
in3.range(8, 0) = in_data[2].range(8, 0);
ap_int<10> in4;
in4.range(9, 0) = in_data[3].range(9, 0);
ap_int<15> in5;
in5.range(14, 0) = in_data[4].range(14, 0);
ap_int<9> in6;
in6.range(8, 0) = in_data[5].range(8, 0);
ap_int<6> in7;
in7.range(5, 0) = in_data[6].range(5, 0);
ap_int<12> in8;
in8.range(11, 0) = in_data[7].range(11, 0);
ap_int<16> in9;
in9.range(15, 0) = in_data[8].range(15, 0);
ap_int<5> in10;
in10.range(4, 0) = in_data[9].range(4, 0);
ap_int<7> in11;
in11.range(6, 0) = in_data[10].range(6, 0);
ap_int<14> in12;
in12.range(13, 0) = in_data[11].range(13, 0);

ap_int<14> m13;
ap_int<16> m14;
ap_int<9> m15;
ap_int<10> m16;
ap_int<10> m17;
ap_int<9> m18;
ap_int<7> m19;
ap_int<7> m20;
ap_int<10> m21;
ap_int<13> m22;
ap_int<4> m23;
ap_int<6> m24;
ap_int<5> m25;
ap_int<11> m26;
ap_int<5> m27;
ap_int<2> m28;
ap_int<6> m29;
ap_int<11> m30;
ap_int<13> m31;
ap_int<16> m32;
ap_int<15> m33;
ap_int<12> m34;
ap_int<11> m35;
ap_int<12> m36;
ap_int<16> m37;
ap_int<15> m38;
ap_int<12> m39;
ap_int<14> m40;
ap_int<16> m41;
ap_int<11> m42;
ap_int<15> m43;
ap_int<12> m44;
ap_int<16> m45;
ap_int<8> m46;
ap_int<11> m47;
ap_int<16> m48;
ap_int<10> m49;
ap_int<13> m50;
ap_int<12> m51;
ap_int<15> m52;
ap_int<10> m53;
ap_int<10> m54;
ap_int<11> m55;
ap_int<6> m56;
ap_int<9> m57;
ap_int<12> m58;
ap_int<13> m59;
ap_int<11> m60;
ap_int<10> m61;
ap_int<7> m62;
ap_int<9> m63;
ap_int<6> m64;
ap_int<12> m65;
ap_int<6> m66;
ap_int<15> m67;

m13 = in12 * in3;
m14 = in5 * in4;
m15 = m14 * in11;
m16 = in11 * in12;
m17 = m15 * in11;
m18 = in8 * m16;
m19 = in9 * m17;
m20 = m18 * m14;
m21 = m18 * m14;
m22 = m19 * m15;
m23 = m19 * m21;
m24 = in12 * m17;
m25 = m17 + m23;
m26 = m20 * m20;
m27 = m17 + m18;
m28 = m25 * m27;
m29 = m28 * m25;
m30 = m24 * m25;
m31 = m29 * m21;
m32 = m27 + m30;
m33 = m31 * m21;
m34 = m31 * m31;
m35 = m26 * m32;
m36 = m26 * m32;
m37 = m29 * m30;
m38 = m27 * m33;
m39 = m33 * m33;
m40 = m28 * m38;
m41 = m36 * m35;
m42 = m33 * m33;
m43 = m38 * m39;
m44 = m39 * m36;
m45 = m33 * m35;
m46 = m34 * m39;
m47 = m38 * m35;
m48 = m45 * m46;
m49 = m40 + m37;
m50 = m48 * m39;
m51 = m39 * m50;
m52 = m48 * m43;
m53 = m42 + m43;
m54 = m44 * m44;
m55 = m48 * m52;
m56 = m49 + m46;
m57 = m45 * m45;
m58 = m48 * m57;
m59 = m56 * m54;
m60 = m59 + m52;
m61 = m49 * m50;
m62 = m57 * m57;
m63 = m60 * m52;
m64 = m62 + m62;
m65 = m61 * m58;
m66 = m65 * m63;
m67 = m65 * m62;

out_data[0] = m13;
out_data[1] = m22;
out_data[2] = m41;
out_data[3] = m47;
out_data[4] = m51;
out_data[5] = m53;
out_data[6] = m55;
out_data[7] = m64;
out_data[8] = m66;
out_data[9] = m67;


}
    