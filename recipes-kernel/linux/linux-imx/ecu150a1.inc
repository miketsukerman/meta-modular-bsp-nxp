ECU_FOLDER = "ecu150a1"

SRC_URI += "\
    file://imx_v8_adv.cfg \
    file://${ECU_FOLDER} \
    file://adv_ecu.patch \
"

DELTA_KERNEL_DEFCONFIG = "${ECU_FOLDER}/ecu150a1_defconfig"

do_configure:append() {
	cp "${WORKDIR}/${ECU_FOLDER}/${MACHINE}.dts" "${S}/arch/arm64/boot/dts/freescale"
	cp "${WORKDIR}/${ECU_FOLDER}/rtc-ht1382.c" "${S}/drivers/rtc/"
	cp "${WORKDIR}/${ECU_FOLDER}/ecu_board.c" "${S}/drivers/char/"
}
