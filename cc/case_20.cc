

#include <stdio.h>
#include "ap_fixed.h"

void case_20(
    ap_int<16> in_data[26],
    ap_int<16> out_data[15]
)
{

#pragma HLS array_partition variable=in_data complete
#pragma HLS array_partition variable=out_data complete

    

ap_int<11> in1;
in1.range(10, 0) = in_data[0].range(10, 0);
ap_int<13> in2;
in2.range(12, 0) = in_data[1].range(12, 0);
ap_int<7> in3;
in3.range(6, 0) = in_data[2].range(6, 0);
ap_int<2> in4;
in4.range(1, 0) = in_data[3].range(1, 0);
ap_int<8> in5;
in5.range(7, 0) = in_data[4].range(7, 0);
ap_int<15> in6;
in6.range(14, 0) = in_data[5].range(14, 0);
ap_int<12> in7;
in7.range(11, 0) = in_data[6].range(11, 0);
ap_int<14> in8;
in8.range(13, 0) = in_data[7].range(13, 0);
ap_int<3> in9;
in9.range(2, 0) = in_data[8].range(2, 0);
ap_int<7> in10;
in10.range(6, 0) = in_data[9].range(6, 0);
ap_int<13> in11;
in11.range(12, 0) = in_data[10].range(12, 0);
ap_int<14> in12;
in12.range(13, 0) = in_data[11].range(13, 0);
ap_int<8> in13;
in13.range(7, 0) = in_data[12].range(7, 0);
ap_int<4> in14;
in14.range(3, 0) = in_data[13].range(3, 0);
ap_int<12> in15;
in15.range(11, 0) = in_data[14].range(11, 0);
ap_int<11> in16;
in16.range(10, 0) = in_data[15].range(10, 0);
ap_int<5> in17;
in17.range(4, 0) = in_data[16].range(4, 0);
ap_int<3> in18;
in18.range(2, 0) = in_data[17].range(2, 0);
ap_int<5> in19;
in19.range(4, 0) = in_data[18].range(4, 0);
ap_int<11> in20;
in20.range(10, 0) = in_data[19].range(10, 0);
ap_int<11> in21;
in21.range(10, 0) = in_data[20].range(10, 0);
ap_int<14> in22;
in22.range(13, 0) = in_data[21].range(13, 0);
ap_int<15> in23;
in23.range(14, 0) = in_data[22].range(14, 0);
ap_int<4> in24;
in24.range(3, 0) = in_data[23].range(3, 0);
ap_int<13> in25;
in25.range(12, 0) = in_data[24].range(12, 0);
ap_int<9> in26;
in26.range(8, 0) = in_data[25].range(8, 0);

ap_int<11> m27;
ap_int<13> m28;
ap_int<5> m29;
ap_int<15> m30;
ap_int<3> m31;
ap_int<12> m32;
ap_int<16> m33;
ap_int<6> m34;
ap_int<11> m35;
ap_int<13> m36;
ap_int<12> m37;
ap_int<6> m38;
ap_int<7> m39;
ap_int<10> m40;
ap_int<9> m41;
ap_int<4> m42;
ap_int<4> m43;
ap_int<7> m44;
ap_int<14> m45;
ap_int<15> m46;
ap_int<10> m47;
ap_int<5> m48;
ap_int<8> m49;
ap_int<9> m50;
ap_int<14> m51;
ap_int<12> m52;
ap_int<14> m53;
ap_int<16> m54;
ap_int<5> m55;
ap_int<14> m56;
ap_int<7> m57;
ap_int<4> m58;
ap_int<5> m59;
ap_int<6> m60;
ap_int<7> m61;
ap_int<14> m62;
ap_int<7> m63;
ap_int<13> m64;
ap_int<14> m65;
ap_int<9> m66;
ap_int<10> m67;
ap_int<16> m68;
ap_int<14> m69;
ap_int<9> m70;
ap_int<6> m71;
ap_int<12> m72;
ap_int<7> m73;
ap_int<9> m74;
ap_int<5> m75;
ap_int<16> m76;
ap_int<16> m77;
ap_int<6> m78;
ap_int<11> m79;
ap_int<6> m80;
ap_int<10> m81;
ap_int<11> m82;
ap_int<6> m83;
ap_int<7> m84;
ap_int<14> m85;
ap_int<8> m86;
ap_int<4> m87;
ap_int<15> m88;
ap_int<8> m89;
ap_int<6> m90;
ap_int<6> m91;
ap_int<15> m92;
ap_int<4> m93;
ap_int<3> m94;

m27 = in12 * in8;
m28 = in15 * in23;
m29 = in3 * in11;
m30 = m28 * in13;
m31 = m29 * in10;
m32 = in11 + in20;
m33 = m32 * m32;
m34 = in14 * in25;
m35 = in15 * in10;
m36 = in14 * in15;
m37 = m30 * m32;
m38 = in22 + in16;
m39 = m30 + m34;
m40 = m39 + in14;
m41 = in19 * m37;
m42 = m34 + in25;
m43 = in19 * m27;
m44 = in18 + m42;
m45 = in23 * m44;
m46 = m27 + in24;
m47 = m30 * m44;
m48 = m36 * m31;
m49 = m45 * in23;
m50 = m29 * m42;
m51 = m49 * m28;
m52 = m45 * m46;
m53 = m33 + m39;
m54 = m33 + m52;
m55 = m42 * m41;
m56 = m36 * m43;
m57 = m45 * m53;
m58 = m48 + m41;
m59 = m40 * m41;
m60 = m51 + m55;
m61 = m49 * m58;
m62 = m58 * m46;
m63 = m42 * m45;
m64 = m55 * m52;
m65 = m62 * m63;
m66 = m60 * m50;
m67 = m61 * m51;
m68 = m52 * m67;
m69 = m68 * m61;
m70 = m62 * m48;
m71 = m63 * m58;
m72 = m62 * m50;
m73 = m60 * m59;
m74 = m60 * m51;
m75 = m51 * m50;
m76 = m57 * m64;
m77 = m51 * m66;
m78 = m65 + m67;
m79 = m62 * m66;
m80 = m71 * m66;
m81 = m61 + m62;
m82 = m61 * m76;
m83 = m73 * m76;
m84 = m77 * m78;
m85 = m70 * m75;
m86 = m60 * m75;
m87 = m73 * m83;
m88 = m77 + m82;
m89 = m80 * m81;
m90 = m75 * m66;
m91 = m71 * m70;
m92 = m74 * m84;
m93 = m72 * m90;
m94 = m83 + m93;

out_data[0] = m35;
out_data[1] = m38;
out_data[2] = m47;
out_data[3] = m54;
out_data[4] = m56;
out_data[5] = m69;
out_data[6] = m79;
out_data[7] = m85;
out_data[8] = m86;
out_data[9] = m87;
out_data[10] = m88;
out_data[11] = m89;
out_data[12] = m91;
out_data[13] = m92;
out_data[14] = m94;


}
    