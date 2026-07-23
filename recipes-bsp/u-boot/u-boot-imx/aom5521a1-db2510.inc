SRC_URI += " \
    file://0001-aom5521a1-update-imx95_evk.h.patch \
    file://0002-Add-extensive-SPL-i.MX-container-boot-logging-for-im.patch \
    file://0004-Restore-runtime-i.MX-container-header-alignment-for-.patch \
    file://0005-Use-IS_ENABLED-CONFIG_IMX95-for-consistency-in-soc.c.patch \
"

do_configure:prepend() {

    # Point to custom device tree
    sed -i "/^CONFIG_DEFAULT_FDT_FILE=/c\CONFIG_DEFAULT_FDT_FILE=\"imx95-aom5521-a1.dtb\"" \
        ${S}/configs/imx95_19x19_evk_defconfig

    # Adjust SPI flash speed for AOM-5521 hardware
    sed -i "/^CONFIG_SF_DEFAULT_SPEED=/c\CONFIG_SF_DEFAULT_SPEED=40000000" \
        ${S}/configs/imx95_19x19_evk_defconfig

    sed -i "/^CONFIG_RTC_EMULATION=/c\# CONFIG_RTC_EMULATION is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig

    sed -i "/^CONFIG_SUPPORT_EMMC_RPMB=y/c\# CONFIG_SUPPORT_EMMC_RPMB is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig

    # Keep SPL in raw MMC mode on user area for this platform.
    sed -i "/^CONFIG_SUPPORT_EMMC_BOOT=y/c\# CONFIG_SUPPORT_EMMC_BOOT is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig

    # Disable USB TCPC (not present on AOM-5521)
    sed -i "/^CONFIG_USB_TCPC=y/c\# CONFIG_USB_TCPC is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig

    # Simplify boot command (no sr_ir_v2_cmd on this board)
    sed -i '/^CONFIG_BOOTCOMMAND=/c\CONFIG_BOOTCOMMAND="bootflow scan -l; run bsp_bootcmd"' \
        ${S}/configs/imx95_19x19_evk_defconfig

    # Add Winbond SPI flash support
    echo "CONFIG_SPI_FLASH_WINBOND=y" >> ${S}/configs/imx95_19x19_evk_defconfig

    # If no recognized container/FIT header is found, allow raw U-Boot fallback.
    grep -q "^CONFIG_SPL_RAW_IMAGE_SUPPORT=y" ${S}/configs/imx95_19x19_evk_defconfig || \
        echo "CONFIG_SPL_RAW_IMAGE_SUPPORT=y" >> ${S}/configs/imx95_19x19_evk_defconfig
}
