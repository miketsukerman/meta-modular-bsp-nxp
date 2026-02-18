SRC_URI += " \
	file://rom5721-db5901.dts;subdir=git/arch/arm64/boot/dts/freescale \
	file://rom5721-db5901.dtsi;subdir=git/arch/arm64/boot/dts/freescale \
	file://rom5721-db5901-dsi2lvds-g215hvn01.dts;subdir=git/arch/arm64/boot/dts/freescale \
	file://lvds-lontium-lt9211.cfg \
	file://0001-ALL-DISPLAY-driver-Add-the-LVDS-power-on-sequence.patch \
	file://0002-imx8mm-ROM-5721-DP-enable-DSI-to-eDP-bridge-IC-sn65d.patch \
	file://0003-imx8mp-ALL-drivers-Update-device-support-display-enh.patch \
"

do_configure:prepend() {
	echo 'dtb-$(CONFIG_ARCH_MXC) += rom5721-db5901.dtb' >> ${S}/arch/arm64/boot/dts/freescale/Makefile
	echo 'dtb-$(CONFIG_ARCH_MXC) += rom5721-db5901-dsi2lvds-g215hvn01.dtb' >> ${S}/arch/arm64/boot/dts/freescale/Makefile
}

DELTA_KERNEL_DEFCONFIG += "lvds-lontium-lt9211.cfg"
