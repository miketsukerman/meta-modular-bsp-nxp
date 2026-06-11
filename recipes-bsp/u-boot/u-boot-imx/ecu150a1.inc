SRC_URI += " \
    file://ecu150a1.dts;subdir=dts/upstream/src/arm64/freescale/ \
    file://lpddr4_timing_1g.c;subdir=board/freescale/imx8mq_evk/ \
    file://lpddr4_timing_2g.c;subdir=board/freescale/imx8mq_evk/ \
    file://lpddr4_timing_4g.c;subdir=board/freescale/imx8mq_evk/ \
    file://ecu150a1-uboot-imx.patch \
"

do_configure:prepend() {
	cp "${UNPACKDIR}/board/freescale/imx8mq_evk/lpddr4_timing_1g.c" \
		   "${S}/board/freescale/imx8mq_evk/"
	cp "${UNPACKDIR}/board/freescale/imx8mq_evk/lpddr4_timing_2g.c" \
		   "${S}/board/freescale/imx8mq_evk/"
	cp "${UNPACKDIR}/board/freescale/imx8mq_evk/lpddr4_timing_4g.c" \
		   "${S}/board/freescale/imx8mq_evk/"

	cp "${UNPACKDIR}/dts/upstream/src/arm64/freescale/ecu150a1.dts" \
		   "${S}/dts/upstream/src/arm64/freescale/ecu150a1.dts"

}