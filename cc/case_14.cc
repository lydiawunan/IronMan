

#include <stdio.h>
#include "ap_fixed.h"

void case_14(
    ap_int<16> in_data[13],
    ap_int<16> out_data[14]
)
{

#pragma HLS array_partition variable=in_data complete
#pragma HLS array_partition variable=out_data complete

    

ap_int<3> in1;
in1.range(2, 0) = in_data[0].range(2, 0);
ap_int<4> in2;
in2.range(3, 0) = in_data[1].range(3, 0);
ap_int<12> in3;
in3.range(11, 0) = in_data[2].range(11, 0);
ap_int<16> in4;
in4.range(15, 0) = in_data[3].range(15, 0);
ap_int<3> in5;
in5.range(2, 0) = in_data[4].range(2, 0);
ap_int<6> in6;
in6.range(5, 0) = in_data[5].range(5, 0);
ap_int<6> in7;
in7.range(5, 0) = in_data[6].range(5, 0);
ap_int<14> in8;
in8.range(13, 0) = in_data[7].range(13, 0);
ap_int<11> in9;
in9.range(10, 0) = in_data[8].range(10, 0);
ap_int<10> in10;
in10.range(9, 0) = in_data[9].range(9, 0);
ap_int<6> in11;
in11.range(5, 0) = in_data[10].range(5, 0);
ap_int<16> in12;
in12.range(15, 0) = in_data[11].range(15, 0);
ap_int<9> in13;
in13.range(8, 0) = in_data[12].range(8, 0);

ap_int<16> m14;
ap_int<11> m15;
ap_int<12> m16;
ap_int<7> m17;
ap_int<10> m18;
ap_int<11> m19;
ap_int<6> m20;
ap_int<8> m21;
ap_int<13> m22;
ap_int<16> m23;
ap_int<16> m24;
ap_int<16> m25;
ap_int<6> m26;
ap_int<16> m27;
ap_int<14> m28;
ap_int<12> m29;
ap_int<12> m30;
ap_int<12> m31;
ap_int<16> m32;
ap_int<15> m33;
ap_int<13> m34;
ap_int<7> m35;
ap_int<10> m36;
ap_int<10> m37;
ap_int<12> m38;
ap_int<16> m39;
ap_int<5> m40;
ap_int<10> m41;
ap_int<10> m42;
ap_int<15> m43;
ap_int<8> m44;
ap_int<14> m45;
ap_int<7> m46;
ap_int<5> m47;
ap_int<15> m48;
ap_int<12> m49;
ap_int<14> m50;
ap_int<9> m51;
ap_int<11> m52;
ap_int<9> m53;
ap_int<13> m54;
ap_int<5> m55;
ap_int<4> m56;
ap_int<6> m57;
ap_int<16> m58;
ap_int<8> m59;
ap_int<7> m60;
ap_int<8> m61;
ap_int<12> m62;
ap_int<15> m63;
ap_int<13> m64;
ap_int<6> m65;
ap_int<6> m66;
ap_int<6> m67;
ap_int<9> m68;
ap_int<10> m69;
ap_int<10> m70;
ap_int<10> m71;
ap_int<12> m72;
ap_int<10> m73;
ap_int<9> m74;

m14 = in11 * in4;
m15 = in7 * in3;
m16 = in11 * in6;
m17 = in8 * in5;
m18 = m14 + in11;
m19 = m16 * m17;
m20 = in9 + in8;
m21 = in11 + m19;
m22 = m15 * m16;
m23 = in12 * m22;
m24 = m14 * in12;
m25 = m15 * m17;
m26 = in13 * m15;
m27 = m19 * m22;
m28 = m24 * m19;
m29 = m28 * m18;
m30 = m21 * m21;
m31 = m20 * m21;
m32 = m22 * m29;
m33 = m28 + m21;
m34 = m28 * m29;
m35 = m24 + m22;
m36 = m25 * m29;
m37 = m30 * m29;
m38 = m27 * m26;
m39 = m35 + m31;
m40 = m31 * m35;
m41 = m35 * m33;
m42 = m29 * m33;
m43 = m35 * m31;
m44 = m43 * m41;
m45 = m44 * m39;
m46 = m36 * m38;
m47 = m38 * m40;
m48 = m41 * m39;
m49 = m44 * m43;
m50 = m42 * m47;
m51 = m40 * m43;
m52 = m42 * m43;
m53 = m43 * m47;
m54 = m49 * m42;
m55 = m53 * m49;
m56 = m47 * m47;
m57 = m56 + m51;
m58 = m49 + m46;
m59 = m58 + m56;
m60 = m57 * m50;
m61 = m58 * m50;
m62 = m56 * m54;
m63 = m62 * m50;
m64 = m57 * m58;
m65 = m57 * m62;
m66 = m63 * m62;
m67 = m66 + m59;
m68 = m63 * m65;
m69 = m61 * m57;
m70 = m67 * m57;
m71 = m69 * m62;
m72 = m65 + m67;
m73 = m64 * m72;
m74 = m62 + m69;

out_data[0] = m23;
out_data[1] = m32;
out_data[2] = m34;
out_data[3] = m37;
out_data[4] = m45;
out_data[5] = m48;
out_data[6] = m52;
out_data[7] = m55;
out_data[8] = m60;
out_data[9] = m68;
out_data[10] = m70;
out_data[11] = m71;
out_data[12] = m73;
out_data[13] = m74;


}
    