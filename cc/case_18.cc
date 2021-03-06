

#include <stdio.h>
#include "ap_fixed.h"

void case_18(
    ap_int<16> in_data[19],
    ap_int<16> out_data[19]
)
{

#pragma HLS array_partition variable=in_data complete
#pragma HLS array_partition variable=out_data complete

    

ap_int<16> in1;
in1.range(15, 0) = in_data[0].range(15, 0);
ap_int<10> in2;
in2.range(9, 0) = in_data[1].range(9, 0);
ap_int<13> in3;
in3.range(12, 0) = in_data[2].range(12, 0);
ap_int<16> in4;
in4.range(15, 0) = in_data[3].range(15, 0);
ap_int<12> in5;
in5.range(11, 0) = in_data[4].range(11, 0);
ap_int<13> in6;
in6.range(12, 0) = in_data[5].range(12, 0);
ap_int<3> in7;
in7.range(2, 0) = in_data[6].range(2, 0);
ap_int<6> in8;
in8.range(5, 0) = in_data[7].range(5, 0);
ap_int<14> in9;
in9.range(13, 0) = in_data[8].range(13, 0);
ap_int<15> in10;
in10.range(14, 0) = in_data[9].range(14, 0);
ap_int<10> in11;
in11.range(9, 0) = in_data[10].range(9, 0);
ap_int<3> in12;
in12.range(2, 0) = in_data[11].range(2, 0);
ap_int<7> in13;
in13.range(6, 0) = in_data[12].range(6, 0);
ap_int<2> in14;
in14.range(1, 0) = in_data[13].range(1, 0);
ap_int<12> in15;
in15.range(11, 0) = in_data[14].range(11, 0);
ap_int<3> in16;
in16.range(2, 0) = in_data[15].range(2, 0);
ap_int<8> in17;
in17.range(7, 0) = in_data[16].range(7, 0);
ap_int<14> in18;
in18.range(13, 0) = in_data[17].range(13, 0);
ap_int<8> in19;
in19.range(7, 0) = in_data[18].range(7, 0);

ap_int<13> m20;
ap_int<2> m21;
ap_int<15> m22;
ap_int<6> m23;
ap_int<4> m24;
ap_int<2> m25;
ap_int<6> m26;
ap_int<15> m27;
ap_int<10> m28;
ap_int<7> m29;
ap_int<3> m30;
ap_int<8> m31;
ap_int<14> m32;
ap_int<2> m33;
ap_int<6> m34;
ap_int<10> m35;
ap_int<11> m36;
ap_int<12> m37;
ap_int<6> m38;
ap_int<15> m39;
ap_int<13> m40;
ap_int<8> m41;
ap_int<7> m42;
ap_int<7> m43;
ap_int<9> m44;
ap_int<6> m45;
ap_int<5> m46;
ap_int<8> m47;
ap_int<7> m48;
ap_int<14> m49;
ap_int<11> m50;
ap_int<11> m51;
ap_int<6> m52;
ap_int<14> m53;
ap_int<5> m54;
ap_int<15> m55;
ap_int<5> m56;
ap_int<13> m57;
ap_int<2> m58;
ap_int<14> m59;
ap_int<16> m60;
ap_int<4> m61;
ap_int<14> m62;
ap_int<15> m63;
ap_int<10> m64;
ap_int<9> m65;
ap_int<7> m66;
ap_int<7> m67;
ap_int<5> m68;
ap_int<13> m69;
ap_int<15> m70;
ap_int<15> m71;
ap_int<10> m72;
ap_int<12> m73;
ap_int<15> m74;
ap_int<15> m75;
ap_int<6> m76;
ap_int<11> m77;
ap_int<13> m78;
ap_int<12> m79;
ap_int<11> m80;
ap_int<7> m81;
ap_int<12> m82;
ap_int<10> m83;
ap_int<14> m84;
ap_int<6> m85;
ap_int<9> m86;
ap_int<14> m87;
ap_int<15> m88;
ap_int<10> m89;
ap_int<10> m90;
ap_int<13> m91;
ap_int<16> m92;
ap_int<10> m93;
ap_int<4> m94;
ap_int<16> m95;
ap_int<8> m96;
ap_int<8> m97;
ap_int<15> m98;
ap_int<8> m99;
ap_int<6> m100;
ap_int<8> m101;
ap_int<7> m102;
ap_int<10> m103;
ap_int<15> m104;
ap_int<5> m105;
ap_int<11> m106;

m20 = in19 * in19;
m21 = in8 * in14;
m22 = in4 * in13;
m23 = m22 * in12;
m24 = m21 * in10;
m25 = in17 * in12;
m26 = in19 * in12;
m27 = in19 * in13;
m28 = in15 * in9;
m29 = in13 * in18;
m30 = in19 * m24;
m31 = in15 * m25;
m32 = m23 * m28;
m33 = m26 * in16;
m34 = m33 + in19;
m35 = in17 * m30;
m36 = m32 * m35;
m37 = m36 * m28;
m38 = m34 + m22;
m39 = m30 + m20;
m40 = m29 * m37;
m41 = m37 * m31;
m42 = m35 * m30;
m43 = m33 + m36;
m44 = m35 * m34;
m45 = m40 + m32;
m46 = m35 * m33;
m47 = m41 * m31;
m48 = m37 * m37;
m49 = m42 * m37;
m50 = m42 * m44;
m51 = m38 * m38;
m52 = m33 * m34;
m53 = m44 * m39;
m54 = m42 * m40;
m55 = m41 + m41;
m56 = m38 + m53;
m57 = m47 * m48;
m58 = m46 * m46;
m59 = m49 * m40;
m60 = m42 * m50;
m61 = m49 * m46;
m62 = m60 * m48;
m63 = m57 * m55;
m64 = m50 + m60;
m65 = m50 * m52;
m66 = m62 * m61;
m67 = m59 * m55;
m68 = m58 * m60;
m69 = m57 + m68;
m70 = m54 * m63;
m71 = m64 + m55;
m72 = m61 * m63;
m73 = m58 * m59;
m74 = m73 + m71;
m75 = m72 * m57;
m76 = m66 * m69;
m77 = m67 * m73;
m78 = m71 * m72;
m79 = m78 * m60;
m80 = m69 * m66;
m81 = m80 + m71;
m82 = m69 * m73;
m83 = m79 * m69;
m84 = m82 + m67;
m85 = m78 * m76;
m86 = m84 * m74;
m87 = m81 * m82;
m88 = m79 * m86;
m89 = m73 * m79;
m90 = m89 * m73;
m91 = m80 + m79;
m92 = m84 + m75;
m93 = m82 * m78;
m94 = m89 * m76;
m95 = m79 + m92;
m96 = m82 * m87;
m97 = m92 * m93;
m98 = m85 + m86;
m99 = m81 * m89;
m100 = m97 * m94;
m101 = m91 * m92;
m102 = m92 * m99;
m103 = m100 * m85;
m104 = m87 * m89;
m105 = m101 + m87;
m106 = m100 * m100;

out_data[0] = m27;
out_data[1] = m43;
out_data[2] = m45;
out_data[3] = m51;
out_data[4] = m56;
out_data[5] = m65;
out_data[6] = m70;
out_data[7] = m77;
out_data[8] = m83;
out_data[9] = m88;
out_data[10] = m90;
out_data[11] = m95;
out_data[12] = m96;
out_data[13] = m98;
out_data[14] = m102;
out_data[15] = m103;
out_data[16] = m104;
out_data[17] = m105;
out_data[18] = m106;


}
    