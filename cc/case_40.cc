

#include <stdio.h>
#include "ap_fixed.h"

void case_40(
    ap_int<16> in_data[11],
    ap_int<16> out_data[12]
)
{

#pragma HLS array_partition variable=in_data complete
#pragma HLS array_partition variable=out_data complete

    

ap_int<14> in1;
in1.range(13, 0) = in_data[0].range(13, 0);
ap_int<4> in2;
in2.range(3, 0) = in_data[1].range(3, 0);
ap_int<8> in3;
in3.range(7, 0) = in_data[2].range(7, 0);
ap_int<10> in4;
in4.range(9, 0) = in_data[3].range(9, 0);
ap_int<5> in5;
in5.range(4, 0) = in_data[4].range(4, 0);
ap_int<16> in6;
in6.range(15, 0) = in_data[5].range(15, 0);
ap_int<11> in7;
in7.range(10, 0) = in_data[6].range(10, 0);
ap_int<12> in8;
in8.range(11, 0) = in_data[7].range(11, 0);
ap_int<10> in9;
in9.range(9, 0) = in_data[8].range(9, 0);
ap_int<16> in10;
in10.range(15, 0) = in_data[9].range(15, 0);
ap_int<13> in11;
in11.range(12, 0) = in_data[10].range(12, 0);

ap_int<9> m12;
ap_int<12> m13;
ap_int<7> m14;
ap_int<8> m15;
ap_int<10> m16;
ap_int<15> m17;
ap_int<5> m18;
ap_int<8> m19;
ap_int<16> m20;
ap_int<10> m21;
ap_int<16> m22;
ap_int<11> m23;
ap_int<15> m24;
ap_int<16> m25;
ap_int<6> m26;
ap_int<10> m27;
ap_int<7> m28;
ap_int<12> m29;
ap_int<10> m30;
ap_int<12> m31;
ap_int<10> m32;
ap_int<8> m33;
ap_int<10> m34;
ap_int<12> m35;
ap_int<13> m36;
ap_int<14> m37;
ap_int<14> m38;
ap_int<14> m39;
ap_int<6> m40;
ap_int<10> m41;
ap_int<8> m42;
ap_int<13> m43;
ap_int<14> m44;
ap_int<13> m45;
ap_int<12> m46;
ap_int<16> m47;
ap_int<12> m48;
ap_int<15> m49;
ap_int<16> m50;
ap_int<9> m51;
ap_int<14> m52;
ap_int<9> m53;
ap_int<16> m54;
ap_int<13> m55;
ap_int<6> m56;
ap_int<11> m57;
ap_int<9> m58;
ap_int<15> m59;
ap_int<10> m60;
ap_int<12> m61;
ap_int<6> m62;
ap_int<11> m63;
ap_int<11> m64;
ap_int<5> m65;
ap_int<12> m66;
ap_int<8> m67;
ap_int<8> m68;
ap_int<13> m69;
ap_int<15> m70;
ap_int<8> m71;
ap_int<5> m72;
ap_int<7> m73;
ap_int<11> m74;
ap_int<6> m75;
ap_int<10> m76;
ap_int<8> m77;
ap_int<15> m78;
ap_int<6> m79;
ap_int<5> m80;
ap_int<5> m81;
ap_int<6> m82;
ap_int<3> m83;
ap_int<3> m84;
ap_int<9> m85;
ap_int<5> m86;
ap_int<10> m87;
ap_int<16> m88;
ap_int<15> m89;
ap_int<14> m90;
ap_int<14> m91;
ap_int<8> m92;
ap_int<12> m93;
ap_int<13> m94;
ap_int<6> m95;
ap_int<14> m96;
ap_int<12> m97;
ap_int<6> m98;
ap_int<8> m99;
ap_int<5> m100;

m12 = in11 * in11;
m13 = in8 * in3;
m14 = in10 * in4;
m15 = in5 * in5;
m16 = m12 * in8;
m17 = m13 * in11;
m18 = m14 * m17;
m19 = m13 * in9;
m20 = in10 * m13;
m21 = in11 * m15;
m22 = m15 + m15;
m23 = m19 * m16;
m24 = m17 * m13;
m25 = m19 * m22;
m26 = m25 * m21;
m27 = m21 * m18;
m28 = m22 * m17;
m29 = m18 * m19;
m30 = m28 * m27;
m31 = m20 + m22;
m32 = m29 * m24;
m33 = m24 * m28;
m34 = m30 + m29;
m35 = m25 * m33;
m36 = m30 + m26;
m37 = m34 + m31;
m38 = m35 * m31;
m39 = m31 * m36;
m40 = m30 * m33;
m41 = m35 * m38;
m42 = m31 * m39;
m43 = m39 * m32;
m44 = m33 * m43;
m45 = m42 * m44;
m46 = m43 * m45;
m47 = m40 + m38;
m48 = m47 * m47;
m49 = m46 * m42;
m50 = m46 * m39;
m51 = m41 * m49;
m52 = m51 * m43;
m53 = m50 + m42;
m54 = m51 * m51;
m55 = m46 * m45;
m56 = m52 * m46;
m57 = m47 * m49;
m58 = m56 * m56;
m59 = m48 * m50;
m60 = m59 * m52;
m61 = m54 * m60;
m62 = m52 * m57;
m63 = m54 * m54;
m64 = m54 * m54;
m65 = m64 * m63;
m66 = m56 * m60;
m67 = m62 * m62;
m68 = m62 * m58;
m69 = m58 * m61;
m70 = m63 + m68;
m71 = m70 * m66;
m72 = m65 * m71;
m73 = m65 * m64;
m74 = m67 * m67;
m75 = m74 + m74;
m76 = m66 * m70;
m77 = m75 * m72;
m78 = m68 * m77;
m79 = m76 + m69;
m80 = m70 * m79;
m81 = m75 * m72;
m82 = m73 + m76;
m83 = m77 + m75;
m84 = m83 * m74;
m85 = m80 + m76;
m86 = m75 * m77;
m87 = m80 * m82;
m88 = m78 * m83;
m89 = m88 * m87;
m90 = m89 * m82;
m91 = m82 * m87;
m92 = m86 * m89;
m93 = m87 + m87;
m94 = m93 * m87;
m95 = m91 * m85;
m96 = m87 * m85;
m97 = m91 + m90;
m98 = m95 + m93;
m99 = m93 + m91;
m100 = m95 + m99;

out_data[0] = m23;
out_data[1] = m37;
out_data[2] = m53;
out_data[3] = m55;
out_data[4] = m81;
out_data[5] = m84;
out_data[6] = m92;
out_data[7] = m94;
out_data[8] = m96;
out_data[9] = m97;
out_data[10] = m98;
out_data[11] = m100;


}
    