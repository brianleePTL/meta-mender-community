FILESEXTRAPATHS_prepend := "${THISDIR}/patches:"

SRC_URI_append_imx6ul-var-dart = " \
    file://0001-mx6ul_var_dart-Remove-unneeded-boot-settings.patch \
    file://0002-imx6ul-var-dart-Find-splash-screen-with-Mender.patch \
"
SRC_URI_remove_imx6ul-var-dart = " \
    file://0006-env-Kconfig-Add-descriptions-so-environment-options-.patch \
"
SRC_URI_append_var-som-mx6 = " \
    file://0001-mx6var_som-Remove-unneeded-boot-settings.patch \
    file://0001-mx6var_som-Find-splash-screen-with-Mender.patch \
"
SRC_URI_remove_var-som-mx6 = " \
    file://0006-env-Kconfig-Add-descriptions-so-environment-options-.patch \
"

MENDER_VARISCITE_UBOOT_PRE_SETUP_COMMANDS = " \
    setenv bootargs console=\${console},\${baudrate}; \
    if test \"${mmcargs}\" != \"\"; then run mmcargs; fi; \
    if test \"${videoargs}\" != \"\"; then run videoargs; fi; \
    if test \"${optargs}\" != \"\"; then run optargs; fi; \
    if test \"${ramsize_check}\" != \"\"; then run ramsize_check; fi; \
    if run loadbootenv; then run importbootenv; fi;  \
    run findfdt; \
    setenv mender_dtb_name \${fdt_file}; \
    setenv kernel_addr_r \${loadaddr}; \
"

MENDER_UBOOT_PRE_SETUP_COMMANDS_var-som-mx6 = "${MENDER_VARISCITE_UBOOT_PRE_SETUP_COMMANDS}"
MENDER_UBOOT_PRE_SETUP_COMMANDS_imx6ul-var-dart = "${MENDER_VARISCITE_UBOOT_PRE_SETUP_COMMANDS}"
