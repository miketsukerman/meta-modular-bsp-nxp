require drivers/watchdog_advantech.inc

SRC_URI += " \
    file://ecu150a1.dts;subdir=git/arch/arm64/boot/dts/freescale \
    file://ecu150a1/imx_v8_adv.cfg \
    file://ecu150a1/adv_ecu.patch \
    file://ecu150a1/ecu150a1_defconfig \
    file://ecu150a1/rtc-ht1382.c \
    file://ecu150a1/ecu_board.c \
    file://ecu150a1/usb/f81604.c \
"

DELTA_KERNEL_DEFCONFIG = "ecu150a1/ecu150a1_defconfig"

do_configure:prepend() {
    echo 'dtb-$(CONFIG_ARCH_MXC) += ecu150a1.dtb' >> ${S}/arch/arm64/boot/dts/freescale/Makefile
    watchdog_advantech_patch
}

do_configure:append() {
    cp "${WORKDIR}/ecu150a1/rtc-ht1382.c" "${S}/drivers/rtc/"
    cp "${WORKDIR}/ecu150a1/ecu_board.c" "${S}/drivers/char/"
}
