

#include <stdio.h>
#include "ap_fixed.h"

void case_29(
    ap_int<16> in_data[11],
    ap_int<16> out_data[15]
)
{

#pragma HLS array_partition variable=in_data complete
#pragma HLS array_partition variable=out_data complete

    

ap_int<9> in1;
in1.range(8, 0) = in_data[0].range(8, 0);
ap_int<8> in2;
in2.range(7, 0) = in_data[1].range(7, 0);
ap_int<8> in3;
in3.range(7, 0) = in_data[2].range(7, 0);
ap_int<5> in4;
in4.range(4, 0) = in_data[3].range(4, 0);
ap_int<3> in5;
in5.range(2, 0) = in_data[4].range(2, 0);
ap_int<5> in6;
in6.range(4, 0) = in_data[5].range(4, 0);
ap_int<16> in7;
in7.range(15, 0) = in_data[6].range(15, 0);
ap_int<12> in8;
in8.range(11, 0) = in_data[7].range(11, 0);
ap_int<15> in9;
in9.range(14, 0) = in_data[8].range(14, 0);
ap_int<9> in10;
in10.range(8, 0) = in_data[9].range(8, 0);
ap_int<8> in11;
in11.range(7, 0) = in_data[10].range(7, 0);

ap_int<11> m12;
ap_int<15> m13;
ap_int<6> m14;
ap_int<15> m15;
ap_int<11> m16;
ap_int<10> m17;
ap_int<15> m18;
ap_int<12> m19;
ap_int<14> m20;
ap_int<16> m21;
ap_int<12> m22;
ap_int<10> m23;
ap_int<16> m24;
ap_int<16> m25;
ap_int<10> m26;
ap_int<8> m27;
ap_int<14> m28;
ap_int<9> m29;
ap_int<12> m30;
ap_int<12> m31;
ap_int<10> m32;
ap_int<8> m33;
ap_int<11> m34;
ap_int<13> m35;
ap_int<16> m36;
ap_int<7> m37;
ap_int<8> m38;
ap_int<6> m39;
ap_int<15> m40;
ap_int<7> m41;
ap_int<5> m42;
ap_int<7> m43;
ap_int<11> m44;
ap_int<16> m45;
ap_int<7> m46;
ap_int<16> m47;
ap_int<12> m48;
ap_int<11> m49;
ap_int<10> m50;
ap_int<8> m51;
ap_int<8> m52;
ap_int<6> m53;
ap_int<10> m54;
ap_int<7> m55;
ap_int<10> m56;
ap_int<7> m57;
ap_int<15> m58;
ap_int<5> m59;
ap_int<16> m60;
ap_int<12> m61;
ap_int<13> m62;
ap_int<10> m63;
ap_int<16> m64;
ap_int<9> m65;
ap_int<11> m66;
ap_int<10> m67;
ap_int<8> m68;
ap_int<11> m69;
ap_int<13> m70;
ap_int<8> m71;
ap_int<11> m72;
ap_int<16> m73;
ap_int<8> m74;
ap_int<16> m75;
ap_int<14> m76;
ap_int<10> m77;
ap_int<5> m78;
ap_int<9> m79;
ap_int<16> m80;
ap_int<8> m81;
ap_int<7> m82;
ap_int<10> m83;
ap_int<7> m84;
ap_int<7> m85;
ap_int<13> m86;
ap_int<9> m87;
ap_int<15> m88;
ap_int<12> m89;
ap_int<7> m90;
ap_int<11> m91;
ap_int<12> m92;
ap_int<16> m93;
ap_int<14> m94;

m12 = in5 * in7;
m13 = in4 * in7;
m14 = in5 * in4;
m15 = in6 * in7;
m16 = in5 * m12;
m17 = in9 * in6;
m18 = in9 * in10;
m19 = in8 * m16;
m20 = m15 * m18;
m21 = m15 * m20;
m22 = m16 + m12;
m23 = m17 * m17;
m24 = m16 * m22;
m25 = m21 + m19;
m26 = m22 * m15;
m27 = m21 + m19;
m28 = m19 + m22;
m29 = m28 * m28;
m30 = m21 * m21;
m31 = m28 * m28;
m32 = m21 * m21;
m33 = m24 * m29;
m34 = m29 * m29;
m35 = m34 + m28;
m36 = m26 + m25;
m37 = m34 * m35;
m38 = m37 + m30;
m39 = m34 + m37;
m40 = m31 * m30;
m41 = m30 * m39;
m42 = m40 * m37;
m43 = m39 * m38;
m44 = m33 + m34;
m45 = m35 * m35;
m46 = m39 * m36;
m47 = m36 * m44;
m48 = m37 * m46;
m49 = m38 * m39;
m50 = m46 * m39;
m51 = m43 * m47;
m52 = m51 * m41;
m53 = m50 * m48;
m54 = m43 * m44;
m55 = m48 * m45;
m56 = m50 * m48;
m57 = m52 + m50;
m58 = m57 * m48;
m59 = m51 * m56;
m60 = m56 * m55;
m61 = m59 * m56;
m62 = m52 * m54;
m63 = m54 * m56;
m64 = m54 * m63;
m65 = m60 * m60;
m66 = m57 * m61;
m67 = m64 * m57;
m68 = m59 + m58;
m69 = m63 * m63;
m70 = m65 + m69;
m71 = m68 * m66;
m72 = m67 * m62;
m73 = m62 * m64;
m74 = m65 * m69;
m75 = m73 * m66;
m76 = m68 * m72;
m77 = m75 * m75;
m78 = m72 * m67;
m79 = m73 * m75;
m80 = m72 * m69;
m81 = m71 * m71;
m82 = m76 + m76;
m83 = m78 * m72;
m84 = m80 * m76;
m85 = m75 * m83;
m86 = m81 * m77;
m87 = m81 * m77;
m88 = m79 + m79;
m89 = m87 + m82;
m90 = m86 * m80;
m91 = m81 * m82;
m92 = m86 * m84;
m93 = m88 * m86;
m94 = m85 * m92;

out_data[0] = m13;
out_data[1] = m14;
out_data[2] = m23;
out_data[3] = m27;
out_data[4] = m32;
out_data[5] = m42;
out_data[6] = m49;
out_data[7] = m53;
out_data[8] = m70;
out_data[9] = m74;
out_data[10] = m89;
out_data[11] = m90;
out_data[12] = m91;
out_data[13] = m93;
out_data[14] = m94;


}
    