

#include <stdio.h>
#include "ap_fixed.h"

void case_41(
    ap_int<16> in_data[16],
    ap_int<16> out_data[9]
)
{

#pragma HLS array_partition variable=in_data complete
#pragma HLS array_partition variable=out_data complete

    

ap_int<4> in1;
in1.range(3, 0) = in_data[0].range(3, 0);
ap_int<7> in2;
in2.range(6, 0) = in_data[1].range(6, 0);
ap_int<11> in3;
in3.range(10, 0) = in_data[2].range(10, 0);
ap_int<6> in4;
in4.range(5, 0) = in_data[3].range(5, 0);
ap_int<10> in5;
in5.range(9, 0) = in_data[4].range(9, 0);
ap_int<13> in6;
in6.range(12, 0) = in_data[5].range(12, 0);
ap_int<4> in7;
in7.range(3, 0) = in_data[6].range(3, 0);
ap_int<9> in8;
in8.range(8, 0) = in_data[7].range(8, 0);
ap_int<4> in9;
in9.range(3, 0) = in_data[8].range(3, 0);
ap_int<9> in10;
in10.range(8, 0) = in_data[9].range(8, 0);
ap_int<3> in11;
in11.range(2, 0) = in_data[10].range(2, 0);
ap_int<5> in12;
in12.range(4, 0) = in_data[11].range(4, 0);
ap_int<7> in13;
in13.range(6, 0) = in_data[12].range(6, 0);
ap_int<6> in14;
in14.range(5, 0) = in_data[13].range(5, 0);
ap_int<10> in15;
in15.range(9, 0) = in_data[14].range(9, 0);
ap_int<11> in16;
in16.range(10, 0) = in_data[15].range(10, 0);

ap_int<9> m17;
ap_int<10> m18;
ap_int<4> m19;
ap_int<7> m20;
ap_int<4> m21;
ap_int<12> m22;
ap_int<5> m23;
ap_int<3> m24;
ap_int<11> m25;
ap_int<11> m26;
ap_int<8> m27;
ap_int<8> m28;
ap_int<12> m29;
ap_int<12> m30;
ap_int<13> m31;
ap_int<5> m32;
ap_int<6> m33;
ap_int<6> m34;
ap_int<14> m35;
ap_int<16> m36;
ap_int<11> m37;
ap_int<4> m38;
ap_int<8> m39;
ap_int<9> m40;
ap_int<16> m41;
ap_int<6> m42;
ap_int<7> m43;
ap_int<9> m44;
ap_int<15> m45;
ap_int<8> m46;
ap_int<9> m47;
ap_int<10> m48;
ap_int<4> m49;
ap_int<14> m50;
ap_int<10> m51;
ap_int<6> m52;
ap_int<4> m53;
ap_int<10> m54;
ap_int<6> m55;
ap_int<6> m56;
ap_int<10> m57;
ap_int<12> m58;
ap_int<16> m59;
ap_int<9> m60;
ap_int<14> m61;
ap_int<9> m62;
ap_int<6> m63;
ap_int<6> m64;
ap_int<7> m65;
ap_int<8> m66;
ap_int<6> m67;
ap_int<8> m68;
ap_int<8> m69;
ap_int<5> m70;
ap_int<8> m71;
ap_int<10> m72;
ap_int<6> m73;
ap_int<10> m74;
ap_int<13> m75;

m17 = in14 * in15;
m18 = in11 * in6;
m19 = m17 * in13;
m20 = in6 * in8;
m21 = m20 * in13;
m22 = in15 * m19;
m23 = m18 * m17;
m24 = m21 * in14;
m25 = in14 * in10;
m26 = in13 * m23;
m27 = in11 * m22;
m28 = m21 * in15;
m29 = m25 * m28;
m30 = m22 * in14;
m31 = m17 + m27;
m32 = m27 * m24;
m33 = m21 + m22;
m34 = m29 * m32;
m35 = m31 * m31;
m36 = m35 * m25;
m37 = m32 * m26;
m38 = m23 * m31;
m39 = m23 + m24;
m40 = m35 * m34;
m41 = m35 * m35;
m42 = m32 + m30;
m43 = m33 * m40;
m44 = m41 * m38;
m45 = m43 * m39;
m46 = m33 * m34;
m47 = m32 * m36;
m48 = m33 * m43;
m49 = m33 + m42;
m50 = m36 * m34;
m51 = m48 * m44;
m52 = m40 * m50;
m53 = m48 * m49;
m54 = m38 * m41;
m55 = m51 * m45;
m56 = m50 * m44;
m57 = m44 * m49;
m58 = m56 * m44;
m59 = m58 + m43;
m60 = m52 * m57;
m61 = m58 * m50;
m62 = m58 * m51;
m63 = m62 * m56;
m64 = m58 * m54;
m65 = m61 + m53;
m66 = m57 * m58;
m67 = m56 * m61;
m68 = m55 * m57;
m69 = m65 + m61;
m70 = m63 * m57;
m71 = m60 + m66;
m72 = m57 * m68;
m73 = m59 * m64;
m74 = m71 * m64;
m75 = m69 * m59;

out_data[0] = m37;
out_data[1] = m46;
out_data[2] = m47;
out_data[3] = m67;
out_data[4] = m70;
out_data[5] = m72;
out_data[6] = m73;
out_data[7] = m74;
out_data[8] = m75;


}
    