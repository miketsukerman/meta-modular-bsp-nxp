SRC_URI += " \
	file://rom5721-db5901.dts;subdir=git/arch/arm64/boot/dts/freescale \
	file://rom5721-db5901.dtsi;subdir=git/arch/arm64/boot/dts/freescale \
	file://rom5721-db5901-lvds.dtsi;subdir=git/arch/arm64/boot/dts/freescale \
	file://rom5721-db5901-dsi2dp.dts;subdir=git/arch/arm64/boot/dts/freescale \
	file://rom5721-db5901-dsi2lvds-g215hvn01.dts;subdir=git/arch/arm64/boot/dts/freescale \
	file://rom5721-db5901-dsi2lvds-lp097x02.dts;subdir=git/arch/arm64/boot/dts/freescale \
	file://rom5721-db5901-dsi2lvds-g150xgel05.dts;subdir=git/arch/arm64/boot/dts/freescale \
	file://rom5721-db5901-dsi2lvds-g070vw01v0.dts;subdir=git/arch/arm64/boot/dts/freescale \
"

SRC_URI += " \
	file://0001-Advantech-modifications-for-panel-simple-driver.patch \
	file://0002-Advantech-modifications-to-pwm-backlight-driver.patch \
	file://0003-Advantech-modifications-to-lcdifv3-crtc.patch \
"

SRC_URI += " \
	file://mipi-dsi.cfg \
"

do_configure:prepend() {
	# Basic DTB for ROM5721-DB5901 is added to the build.
	echo 'dtb-$(CONFIG_ARCH_MXC) += rom5721-db5901.dtb' >> ${S}/arch/arm64/boot/dts/freescale/Makefile

	# DSI to LVDS bridge panels are currently supported, so the corresponding DTBs are added to the build.
	echo 'dtb-$(CONFIG_ARCH_MXC) += rom5721-db5901-dsi2lvds-g215hvn01.dtb' >> ${S}/arch/arm64/boot/dts/freescale/Makefile
	echo 'dtb-$(CONFIG_ARCH_MXC) += rom5721-db5901-dsi2lvds-lp097x02.dtb' >> ${S}/arch/arm64/boot/dts/freescale/Makefile
	echo 'dtb-$(CONFIG_ARCH_MXC) += rom5721-db5901-dsi2lvds-g150xgel05.dtb' >> ${S}/arch/arm64/boot/dts/freescale/Makefile
	echo 'dtb-$(CONFIG_ARCH_MXC) += rom5721-db5901-dsi2lvds-g070vw01v0.dtb' >> ${S}/arch/arm64/boot/dts/freescale/Makefile

# The DSI to DP bridge is not currently supported, so the corresponding DTB is not added to the build.
# 	echo 'dtb-$(CONFIG_ARCH_MXC) += rom5721-db5901-dsi2dp.dtb' >> ${S}/arch/arm64/boot/dts/freescale/Makefile
}

# DSI to LVDS bridge panels are currently supported, so the corresponding kernel configuration fragments are added to the build.
DELTA_KERNEL_DEFCONFIG += " \
		mipi-dsi.cfg \
"
