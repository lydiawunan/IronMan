

#include <stdio.h>
#include "ap_fixed.h"

void case_23(
    ap_int<16> in_data[12],
    ap_int<16> out_data[12]
)
{

#pragma HLS array_partition variable=in_data complete
#pragma HLS array_partition variable=out_data complete

    

ap_int<14> in1;
in1.range(13, 0) = in_data[0].range(13, 0);
ap_int<8> in2;
in2.range(7, 0) = in_data[1].range(7, 0);
ap_int<15> in3;
in3.range(14, 0) = in_data[2].range(14, 0);
ap_int<12> in4;
in4.range(11, 0) = in_data[3].range(11, 0);
ap_int<3> in5;
in5.range(2, 0) = in_data[4].range(2, 0);
ap_int<8> in6;
in6.range(7, 0) = in_data[5].range(7, 0);
ap_int<7> in7;
in7.range(6, 0) = in_data[6].range(6, 0);
ap_int<5> in8;
in8.range(4, 0) = in_data[7].range(4, 0);
ap_int<7> in9;
in9.range(6, 0) = in_data[8].range(6, 0);
ap_int<15> in10;
in10.range(14, 0) = in_data[9].range(14, 0);
ap_int<9> in11;
in11.range(8, 0) = in_data[10].range(8, 0);
ap_int<6> in12;
in12.range(5, 0) = in_data[11].range(5, 0);

ap_int<8> m13;
ap_int<6> m14;
ap_int<8> m15;
ap_int<9> m16;
ap_int<12> m17;
ap_int<14> m18;
ap_int<11> m19;
ap_int<11> m20;
ap_int<13> m21;
ap_int<8> m22;
ap_int<11> m23;
ap_int<12> m24;
ap_int<3> m25;
ap_int<12> m26;
ap_int<8> m27;
ap_int<14> m28;
ap_int<11> m29;
ap_int<8> m30;
ap_int<7> m31;
ap_int<9> m32;
ap_int<9> m33;
ap_int<6> m34;
ap_int<9> m35;
ap_int<9> m36;
ap_int<6> m37;
ap_int<9> m38;
ap_int<12> m39;
ap_int<10> m40;
ap_int<8> m41;
ap_int<4> m42;
ap_int<7> m43;
ap_int<9> m44;
ap_int<14> m45;
ap_int<5> m46;
ap_int<12> m47;
ap_int<11> m48;
ap_int<6> m49;
ap_int<6> m50;
ap_int<3> m51;
ap_int<11> m52;
ap_int<13> m53;
ap_int<10> m54;
ap_int<10> m55;
ap_int<12> m56;
ap_int<4> m57;
ap_int<4> m58;
ap_int<5> m59;
ap_int<7> m60;
ap_int<4> m61;
ap_int<12> m62;
ap_int<6> m63;
ap_int<6> m64;
ap_int<4> m65;
ap_int<7> m66;
ap_int<6> m67;
ap_int<7> m68;
ap_int<4> m69;
ap_int<6> m70;
ap_int<4> m71;
ap_int<10> m72;
ap_int<15> m73;
ap_int<3> m74;
ap_int<5> m75;
ap_int<8> m76;
ap_int<8> m77;
ap_int<10> m78;
ap_int<2> m79;
ap_int<2> m80;
ap_int<5> m81;
ap_int<4> m82;
ap_int<4> m83;
ap_int<5> m84;
ap_int<8> m85;
ap_int<4> m86;
ap_int<5> m87;
ap_int<6> m88;
ap_int<7> m89;
ap_int<9> m90;
ap_int<5> m91;
ap_int<12> m92;
ap_int<8> m93;
ap_int<13> m94;
ap_int<12> m95;
ap_int<4> m96;
ap_int<16> m97;
ap_int<5> m98;
ap_int<12> m99;
ap_int<9> m100;
ap_int<10> m101;
ap_int<16> m102;
ap_int<8> m103;
ap_int<4> m104;
ap_int<6> m105;
ap_int<16> m106;
ap_int<15> m107;
ap_int<9> m108;
ap_int<9> m109;
ap_int<12> m110;
ap_int<12> m111;
ap_int<7> m112;
ap_int<16> m113;
ap_int<15> m114;
ap_int<11> m115;
ap_int<8> m116;
ap_int<10> m117;
ap_int<13> m118;
ap_int<8> m119;

m13 = in6 * in1;
m14 = in2 * in11;
m15 = m14 * in9;
m16 = in4 * in9;
m17 = m14 * in9;
m18 = in10 * m17;
m19 = m13 + m15;
m20 = in10 * in11;
m21 = m16 * m16;
m22 = m16 * m13;
m23 = m16 * m14;
m24 = m13 * m17;
m25 = m14 * m16;
m26 = m18 * m22;
m27 = m22 * m23;
m28 = m23 + m16;
m29 = m22 + m25;
m30 = m19 * m28;
m31 = m23 * m23;
m32 = m24 * m26;
m33 = m21 + m21;
m34 = m28 * m29;
m35 = m32 * m27;
m36 = m30 + m25;
m37 = m25 * m25;
m38 = m36 * m29;
m39 = m32 * m27;
m40 = m39 * m31;
m41 = m34 * m30;
m42 = m34 * m41;
m43 = m37 * m38;
m44 = m43 * m38;
m45 = m42 * m39;
m46 = m41 * m42;
m47 = m36 * m46;
m48 = m45 * m44;
m49 = m42 * m46;
m50 = m48 * m40;
m51 = m44 * m49;
m52 = m48 * m50;
m53 = m43 * m52;
m54 = m51 + m47;
m55 = m49 * m53;
m56 = m55 + m53;
m57 = m50 * m51;
m58 = m49 * m52;
m59 = m57 + m55;
m60 = m57 * m52;
m61 = m51 * m60;
m62 = m55 * m53;
m63 = m58 * m59;
m64 = m56 * m54;
m65 = m54 * m58;
m66 = m54 * m60;
m67 = m64 * m61;
m68 = m59 * m62;
m69 = m67 + m60;
m70 = m63 * m58;
m71 = m64 * m69;
m72 = m61 * m64;
m73 = m62 + m71;
m74 = m63 * m70;
m75 = m67 * m70;
m76 = m74 * m66;
m77 = m65 * m70;
m78 = m76 * m66;
m79 = m71 * m71;
m80 = m75 * m70;
m81 = m70 * m80;
m82 = m78 * m75;
m83 = m76 * m72;
m84 = m80 * m83;
m85 = m77 + m74;
m86 = m84 * m81;
m87 = m75 * m84;
m88 = m78 * m87;
m89 = m88 * m80;
m90 = m89 * m82;
m91 = m79 * m83;
m92 = m83 * m90;
m93 = m86 + m81;
m94 = m93 * m90;
m95 = m92 * m83;
m96 = m88 * m94;
m97 = m94 * m92;
m98 = m86 * m91;
m99 = m93 * m91;
m100 = m91 * m88;
m101 = m97 * m100;
m102 = m95 * m91;
m103 = m99 * m94;
m104 = m96 * m93;
m105 = m101 + m101;
m106 = m102 * m97;
m107 = m98 * m97;
m108 = m104 + m105;
m109 = m104 * m99;
m110 = m103 * m107;
m111 = m104 * m110;
m112 = m109 * m103;
m113 = m106 * m112;
m114 = m110 * m104;
m115 = m112 * m113;
m116 = m112 * m114;
m117 = m105 * m112;
m118 = m107 * m113;
m119 = m117 * m117;

out_data[0] = m20;
out_data[1] = m33;
out_data[2] = m35;
out_data[3] = m68;
out_data[4] = m73;
out_data[5] = m85;
out_data[6] = m108;
out_data[7] = m111;
out_data[8] = m115;
out_data[9] = m116;
out_data[10] = m118;
out_data[11] = m119;


}
    