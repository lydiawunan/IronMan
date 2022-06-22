

#include <stdio.h>
#include "ap_fixed.h"

void case_19(
    ap_int<16> in_data[17],
    ap_int<16> out_data[16]
)
{

#pragma HLS array_partition variable=in_data complete
#pragma HLS array_partition variable=out_data complete

    

ap_int<9> in1;
in1.range(8, 0) = in_data[0].range(8, 0);
ap_int<9> in2;
in2.range(8, 0) = in_data[1].range(8, 0);
ap_int<7> in3;
in3.range(6, 0) = in_data[2].range(6, 0);
ap_int<5> in4;
in4.range(4, 0) = in_data[3].range(4, 0);
ap_int<13> in5;
in5.range(12, 0) = in_data[4].range(12, 0);
ap_int<15> in6;
in6.range(14, 0) = in_data[5].range(14, 0);
ap_int<4> in7;
in7.range(3, 0) = in_data[6].range(3, 0);
ap_int<15> in8;
in8.range(14, 0) = in_data[7].range(14, 0);
ap_int<15> in9;
in9.range(14, 0) = in_data[8].range(14, 0);
ap_int<14> in10;
in10.range(13, 0) = in_data[9].range(13, 0);
ap_int<3> in11;
in11.range(2, 0) = in_data[10].range(2, 0);
ap_int<9> in12;
in12.range(8, 0) = in_data[11].range(8, 0);
ap_int<12> in13;
in13.range(11, 0) = in_data[12].range(11, 0);
ap_int<7> in14;
in14.range(6, 0) = in_data[13].range(6, 0);
ap_int<11> in15;
in15.range(10, 0) = in_data[14].range(10, 0);
ap_int<3> in16;
in16.range(2, 0) = in_data[15].range(2, 0);
ap_int<9> in17;
in17.range(8, 0) = in_data[16].range(8, 0);

ap_int<14> m18;
ap_int<7> m19;
ap_int<4> m20;
ap_int<16> m21;
ap_int<8> m22;
ap_int<5> m23;
ap_int<14> m24;
ap_int<6> m25;
ap_int<12> m26;
ap_int<11> m27;
ap_int<12> m28;
ap_int<8> m29;
ap_int<2> m30;
ap_int<9> m31;
ap_int<12> m32;
ap_int<2> m33;
ap_int<9> m34;
ap_int<7> m35;
ap_int<13> m36;
ap_int<3> m37;
ap_int<8> m38;
ap_int<4> m39;
ap_int<12> m40;
ap_int<12> m41;
ap_int<16> m42;
ap_int<5> m43;
ap_int<13> m44;
ap_int<4> m45;
ap_int<4> m46;
ap_int<6> m47;
ap_int<8> m48;
ap_int<11> m49;
ap_int<5> m50;
ap_int<5> m51;
ap_int<9> m52;
ap_int<16> m53;
ap_int<10> m54;
ap_int<11> m55;
ap_int<11> m56;
ap_int<16> m57;
ap_int<14> m58;
ap_int<9> m59;
ap_int<10> m60;
ap_int<16> m61;
ap_int<16> m62;
ap_int<6> m63;
ap_int<8> m64;
ap_int<9> m65;
ap_int<8> m66;
ap_int<12> m67;
ap_int<5> m68;
ap_int<11> m69;
ap_int<14> m70;
ap_int<6> m71;
ap_int<9> m72;
ap_int<7> m73;
ap_int<11> m74;
ap_int<16> m75;
ap_int<7> m76;
ap_int<16> m77;
ap_int<16> m78;
ap_int<7> m79;
ap_int<6> m80;
ap_int<14> m81;
ap_int<13> m82;
ap_int<8> m83;
ap_int<8> m84;
ap_int<16> m85;
ap_int<8> m86;
ap_int<13> m87;
ap_int<7> m88;

m18 = in4 * in5;
m19 = in16 * in13;
m20 = in10 + in4;
m21 = in10 * m18;
m22 = m19 * m21;
m23 = in8 * m19;
m24 = m21 * m21;
m25 = m19 + in9;
m26 = m19 * m25;
m27 = m24 * m25;
m28 = m23 * m27;
m29 = in16 * in17;
m30 = in16 * in14;
m31 = m30 * m26;
m32 = m21 * m18;
m33 = m25 * m30;
m34 = m32 * m19;
m35 = m30 * m21;
m36 = m26 * m26;
m37 = m31 + m23;
m38 = m27 * m33;
m39 = m23 * m32;
m40 = m36 + m37;
m41 = m37 * m32;
m42 = m35 * m31;
m43 = m26 * m29;
m44 = m32 * m33;
m45 = m39 * m29;
m46 = m37 * m33;
m47 = m33 * m44;
m48 = m37 * m31;
m49 = m41 + m46;
m50 = m33 * m40;
m51 = m47 * m41;
m52 = m46 * m42;
m53 = m40 * m46;
m54 = m43 * m49;
m55 = m39 * m44;
m56 = m53 * m40;
m57 = m44 * m49;
m58 = m50 * m49;
m59 = m50 * m51;
m60 = m52 * m47;
m61 = m49 + m55;
m62 = m46 + m58;
m63 = m46 * m50;
m64 = m53 * m54;
m65 = m56 + m53;
m66 = m63 * m59;
m67 = m62 * m60;
m68 = m56 * m54;
m69 = m54 * m67;
m70 = m57 * m61;
m71 = m60 + m66;
m72 = m65 * m64;
m73 = m65 * m67;
m74 = m58 * m66;
m75 = m63 * m69;
m76 = m63 * m69;
m77 = m61 * m75;
m78 = m66 * m72;
m79 = m70 + m73;
m80 = m73 * m76;
m81 = m78 + m69;
m82 = m65 * m81;
m83 = m68 * m72;
m84 = m72 * m70;
m85 = m83 + m78;
m86 = m85 * m69;
m87 = m70 * m72;
m88 = m83 * m84;

out_data[0] = m20;
out_data[1] = m22;
out_data[2] = m28;
out_data[3] = m34;
out_data[4] = m38;
out_data[5] = m45;
out_data[6] = m48;
out_data[7] = m71;
out_data[8] = m74;
out_data[9] = m77;
out_data[10] = m79;
out_data[11] = m80;
out_data[12] = m82;
out_data[13] = m86;
out_data[14] = m87;
out_data[15] = m88;


}
    