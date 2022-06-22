

#include <stdio.h>
#include "ap_fixed.h"

void case_50(
    ap_int<16> in_data[17],
    ap_int<16> out_data[13]
)
{

#pragma HLS array_partition variable=in_data complete
#pragma HLS array_partition variable=out_data complete

    

ap_int<9> in1;
in1.range(8, 0) = in_data[0].range(8, 0);
ap_int<12> in2;
in2.range(11, 0) = in_data[1].range(11, 0);
ap_int<4> in3;
in3.range(3, 0) = in_data[2].range(3, 0);
ap_int<3> in4;
in4.range(2, 0) = in_data[3].range(2, 0);
ap_int<6> in5;
in5.range(5, 0) = in_data[4].range(5, 0);
ap_int<4> in6;
in6.range(3, 0) = in_data[5].range(3, 0);
ap_int<5> in7;
in7.range(4, 0) = in_data[6].range(4, 0);
ap_int<8> in8;
in8.range(7, 0) = in_data[7].range(7, 0);
ap_int<14> in9;
in9.range(13, 0) = in_data[8].range(13, 0);
ap_int<2> in10;
in10.range(1, 0) = in_data[9].range(1, 0);
ap_int<6> in11;
in11.range(5, 0) = in_data[10].range(5, 0);
ap_int<15> in12;
in12.range(14, 0) = in_data[11].range(14, 0);
ap_int<13> in13;
in13.range(12, 0) = in_data[12].range(12, 0);
ap_int<16> in14;
in14.range(15, 0) = in_data[13].range(15, 0);
ap_int<6> in15;
in15.range(5, 0) = in_data[14].range(5, 0);
ap_int<3> in16;
in16.range(2, 0) = in_data[15].range(2, 0);
ap_int<10> in17;
in17.range(9, 0) = in_data[16].range(9, 0);

ap_int<11> m18;
ap_int<5> m19;
ap_int<11> m20;
ap_int<13> m21;
ap_int<3> m22;
ap_int<12> m23;
ap_int<4> m24;
ap_int<12> m25;
ap_int<3> m26;
ap_int<6> m27;
ap_int<13> m28;
ap_int<15> m29;
ap_int<8> m30;
ap_int<8> m31;
ap_int<4> m32;
ap_int<7> m33;
ap_int<5> m34;
ap_int<9> m35;
ap_int<12> m36;
ap_int<15> m37;
ap_int<12> m38;
ap_int<12> m39;
ap_int<13> m40;
ap_int<11> m41;
ap_int<14> m42;
ap_int<15> m43;
ap_int<11> m44;
ap_int<14> m45;
ap_int<6> m46;
ap_int<6> m47;
ap_int<6> m48;
ap_int<5> m49;
ap_int<15> m50;
ap_int<9> m51;
ap_int<7> m52;
ap_int<5> m53;
ap_int<7> m54;
ap_int<8> m55;
ap_int<2> m56;
ap_int<7> m57;
ap_int<10> m58;
ap_int<8> m59;
ap_int<4> m60;
ap_int<3> m61;
ap_int<7> m62;
ap_int<4> m63;
ap_int<6> m64;
ap_int<9> m65;
ap_int<5> m66;
ap_int<6> m67;
ap_int<9> m68;
ap_int<3> m69;
ap_int<12> m70;
ap_int<9> m71;
ap_int<6> m72;
ap_int<5> m73;
ap_int<9> m74;
ap_int<12> m75;
ap_int<15> m76;
ap_int<6> m77;
ap_int<8> m78;
ap_int<4> m79;
ap_int<7> m80;
ap_int<12> m81;
ap_int<10> m82;
ap_int<8> m83;
ap_int<12> m84;
ap_int<15> m85;
ap_int<3> m86;
ap_int<6> m87;
ap_int<2> m88;
ap_int<6> m89;
ap_int<5> m90;

m18 = in2 * in17;
m19 = in12 * in6;
m20 = in14 * m19;
m21 = in15 * in8;
m22 = in7 * in15;
m23 = in15 * in9;
m24 = m23 * in7;
m25 = in13 * in8;
m26 = m22 * m19;
m27 = m20 * m23;
m28 = in12 * m22;
m29 = m22 * in12;
m30 = m28 * m24;
m31 = m30 * m25;
m32 = in16 + in16;
m33 = m19 * m26;
m34 = m26 + m32;
m35 = m29 * m25;
m36 = m28 + m27;
m37 = m27 * m20;
m38 = m31 * m33;
m39 = m24 * m38;
m40 = m38 * m34;
m41 = m29 * m38;
m42 = m29 * m40;
m43 = m37 * m33;
m44 = m37 * m27;
m45 = m41 * m37;
m46 = m38 * m45;
m47 = m37 * m33;
m48 = m31 * m44;
m49 = m35 * m33;
m50 = m39 * m45;
m51 = m45 * m42;
m52 = m47 * m36;
m53 = m49 * m44;
m54 = m39 * m46;
m55 = m52 * m45;
m56 = m49 * m48;
m57 = m53 + m45;
m58 = m51 * m41;
m59 = m44 * m51;
m60 = m49 + m56;
m61 = m49 * m54;
m62 = m52 * m50;
m63 = m52 * m53;
m64 = m63 + m59;
m65 = m60 * m62;
m66 = m53 * m65;
m67 = m66 + m57;
m68 = m59 * m62;
m69 = m67 * m57;
m70 = m68 * m66;
m71 = m69 + m62;
m72 = m66 * m69;
m73 = m59 * m65;
m74 = m66 * m62;
m75 = m58 * m74;
m76 = m72 * m65;
m77 = m72 + m62;
m78 = m70 * m75;
m79 = m75 * m62;
m80 = m66 * m71;
m81 = m70 * m78;
m82 = m75 * m67;
m83 = m80 * m74;
m84 = m81 * m75;
m85 = m82 * m75;
m86 = m80 * m79;
m87 = m71 + m85;
m88 = m77 * m86;
m89 = m78 + m75;
m90 = m79 * m84;

out_data[0] = m18;
out_data[1] = m21;
out_data[2] = m43;
out_data[3] = m55;
out_data[4] = m61;
out_data[5] = m64;
out_data[6] = m73;
out_data[7] = m76;
out_data[8] = m83;
out_data[9] = m87;
out_data[10] = m88;
out_data[11] = m89;
out_data[12] = m90;


}
    