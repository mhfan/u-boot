/*
 * (C) Copyright 2006-2008
 * Texas Instruments.
 * Richard Woodruff <r-woodruff2@ti.com>
 * Syed Mohammed Khasim <x0khasim@ti.com>
 *
 * Configuration settings for the TI OMAP3530 Beagle board.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 */
#define CONFIG_ARMV7		1	/* This is an ARM V7 CPU core */
#define CONFIG_OMAP		1	/* in a TI OMAP core */
#define CONFIG_OMAP34XX		1	/* which is a 34XX */
#define CONFIG_OMAP3430		1	/* which is in a 3430 */
#define CONFIG_OMAP3_BEAGLE	1	/* working with BEAGLE */

#define CONFIG_SDRC	/* The chip has SDRC controller */

#include <asm/arch/cpu.h>		/* get chip and board defs */
#include <asm/arch/omap3.h>

/*
 * Display CPU and Board information
 */
#define CONFIG_DISPLAY_CPUINFO		1
#define CONFIG_DISPLAY_BOARDINFO	1

/* Clock Defines */
#define V_OSCK			26000000	/* Clock output from T2 */
#define V_SCLK			(V_OSCK >> 1)

#undef CONFIG_USE_IRQ				/* no support for IRQs */
#define CONFIG_MISC_INIT_R

#define CONFIG_OF_LIBFDT		1

#define CONFIG_CMDLINE_TAG		1	/* enable passing of ATAGs */
#define CONFIG_SETUP_MEMORY_TAGS	1
#define CONFIG_REVISION_TAG		1	/* XXX: */
#define CONFIG_INITRD_TAG		1

/*
 * Size of malloc() pool
 */
#define CONFIG_ENV_SIZE			(128 << 10)	/* XXX: */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + (128 << 10))

/*
 * Hardware drivers
 */

/*
 * NS16550 Configuration
 */
#define V_NS16550_CLK			48000000	/* 48MHz (APLL96/2) */

#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	(-4)
#define CONFIG_SYS_NS16550_CLK		V_NS16550_CLK

/*
 * select serial console configuration
 */
#define CONFIG_SYS_NS16550_COM3		OMAP34XX_UART3
#define CONFIG_CONS_INDEX		3
#define CONFIG_SERIAL3			3	/* UART3 on Beagle Rev 2 */

#define CONFIG_SYS_BAUDRATE_TABLE	{4800, 9600, 19200, 38400, 57600,\
					115200}
#define CONFIG_BAUDRATE			115200

/* MMC */
#define CONFIG_MMC			1
#define CONFIG_OMAP_HSMMC		1
#define CONFIG_GENERIC_MMC		1
/*#define CONFIG_SYS_MMC_SET_DEV		1 */
#define CONFIG_DOS_PARTITION		1

/* Status LED */
#define CONFIG_STATUS_LED		1
#define CONFIG_BOARD_SPECIFIC_LED	1
#define STATUS_LED_BIT			0x01
#define STATUS_LED_STATE		STATUS_LED_ON
#define STATUS_LED_PERIOD		(CONFIG_SYS_HZ / 2)
#define STATUS_LED_BIT1			0x02
#define STATUS_LED_STATE1		STATUS_LED_ON
#define STATUS_LED_PERIOD1		(CONFIG_SYS_HZ / 2)
#define STATUS_LED_BOOT			STATUS_LED_BIT
#define STATUS_LED_GREEN		STATUS_LED_BIT1

/* DDR - I use Micron DDR */
#define CONFIG_OMAP3_MICRON_DDR		1

/* USB */
#define CONFIG_MUSB_HCD			1
#define CONFIG_MUSB_UDC			1
#define CONFIG_USB_OMAP3		1
#define CONFIG_TWL4030_USB		1

/* USB device configuration */
#define CONFIG_USB_DEVICE		1
#define CONFIG_USB_TTY			1
#define CONFIG_SYS_CONSOLE_IS_IN_ENV	1
#define CONFIG_CONSOLE_MUX		1

/* USB EHCI */
#define CONFIG_CMD_USB
#define CONFIG_USB_EHCI
#define CONFIG_SYS_USB_EHCI_MAX_ROOT_PORTS 3

/* commands to include */
#include <config_cmd_default.h>

#define CONFIG_CMD_I2C		/* I2C serial bus support	*/

#define CONFIG_CMD_MMC		/* MMC support			*/
#define CONFIG_CMD_FAT		/* FAT support			*/
/*#define CONFIG_CMD_EXT2		// EXT2 Support			*/

#define CONFIG_USB_STORAGE	/* USB storage support		*/

#define CONFIG_CMD_MTDPARTS	/* Enable MTD parts commands	*/
#define CONFIG_CMD_NAND		/* NAND support			*/
/*#define CONFIG_CMD_JFFS2	// JFFS2 Support		*/
#define CONFIG_CMD_UBI		/* UBI support			*/

#define CONFIG_CMD_LED		/* LED support			*/
#define CONFIG_CMD_CACHE

#undef CONFIG_CMD_FPGA		/* FPGA configuration Support	*/
#undef CONFIG_CMD_IMLS		/* List all found images	*/
#undef CONFIG_CMD_NET		/* bootp, tftpboot, rarpboot	*/
#undef CONFIG_CMD_NFS		/* NFS support			*/
#define CONFIG_SYS_NO_FLASH

#define CONFIG_HARD_I2C			1
#define CONFIG_SYS_I2C_SPEED		100000	/* XXX: 400k? */
#define CONFIG_SYS_I2C_SLAVE		1
#define CONFIG_SYS_I2C_BUS		0
#define CONFIG_SYS_I2C_BUS_SELECT	1
#define CONFIG_I2C_MULTI_BUS		1
#define CONFIG_DRIVER_OMAP34XX_I2C	1

/* TWL4030 */
#define CONFIG_TWL4030_POWER		1
#define CONFIG_TWL4030_LED		1

/* MTD */
#define CONFIG_MTD_PARTITIONS	/* needed for mtdparts commands */
#define CONFIG_MTD_DEVICE	/* needed for mtdparts commands */
#define MTDIDS_DEFAULT			"nand0=nand"
#define MTDPARTS_DEFAULT		"mtdparts=nand:512k(x-loader)," \
					"1920k(u-boot),128k(u-boot-env)," \
					"4m(kernel),-(fs)"	/* XXX: */

/* NAND */
#define CONFIG_NAND_OMAP_GPMC
#define CONFIG_SYS_NAND_QUIET_TEST	1
#define GPMC_NAND_ECC_LP_x16_LAYOUT	1
#define CONFIG_SYS_MAX_NAND_DEVICE	1	/* Max number of NAND devices */
#define CONFIG_SYS_NAND_ADDR		NAND_BASE
#define CONFIG_SYS_NAND_BASE		NAND_BASE
	/* physical address to access nand at CS0 */

#define CONFIG_JFFS2_NAND
/* nand device jffs2 lives on */
#define CONFIG_JFFS2_DEV		"nand0"
/* start of jffs2 partition */
#define CONFIG_JFFS2_PART_OFFSET	0x680000
#define CONFIG_JFFS2_PART_SIZE		0xf980000	/* size of jffs2 */
							/* partition */

/* Environment information */
#define CONFIG_BOOTDELAY		1

#define CONFIG_ENV_OVERWRITE

#define CONFIG_EXTRA_ENV_SETTINGS \
	"rdaddr=0x81600000\0loadaddr=0x82000000\0" \
	"usbtty=cdc_acm\0optargs=panic=1 lpj=1970176\0" \
	"console=console=tty0 console=ttyS2,115200n8 quiet\0" \
	"mmcdev=0\0mpurate=auto\0vram=12M\0defaultdisplay=dvi\0" \
	"dss1spec=video=omapfb:vram:3M,mode:" \
		"1280x1024@60,vxres=1280,vyres=1024\0" \
	"videospec=omapfb.mode=dvi:1280x1024MR-16@60 " \
		"omapdss.def_disp=${defaultdisplay} " \
		"vram=${vram} mpurate=${mpurate}\0" \
	"nfsargs=setenv bootargs root=/dev/nfs rw " \
		"${console} ${videospec} ${optargs} " \
		"nfsroot=/home/mhfan/devel/beagle/rootfs,nolock " \
		"ip=192.168.1.53:192.168.1.54:192.168.1.1\0" \
	"mmcargs=setenv bootargs ${console} ${videospec} ${optargs} " \
		"root=/dev/mmcblk0p2 rw rootfstype=ext4 rootwait\0" \
	"nandargs=setenv bootargs ${console} ${videospec} ${optargs} " \
		"root=/dev/mtdblock4 rw rootfstype=yaffs2\0" \
	"irfsargs=setenv bootargs rdinit=/sbin/init\0" \
		"${console} ${videospec} ${optargs}\0" \
	"ramargs=setenv bootargs root=/dev/ram0 rw " \
		"${console} ${videospec} ${optargs} " \
		"ramdisk_size=32768 initrd=${rdaddr},32M\0" \
	"ubifsargs=setenv bootargs ${console} ${videospec} ${optargs} " \
		"root=ubi0:beagleroot ubi.mtd=4 rw rootfstype=ubifs\0" \
	"loadbootenv=fatload mmc ${mmcdev} ${loadaddr} uEnv.txt\0" \
	"loadbootscript=fatload mmc ${mmcdev} ${loadaddr} boot.scr\0" \
	"bootscript=echo Running bootscript from mmc${mmcdev} ...; " \
		"source ${loadaddr}\0" \
	"importbootenv=echo Importing environment from mmc ...; " \
		"env import -t ${loadaddr} ${filesize}\0" \
	"loaduimage=fatload mmc ${mmcdev} ${loadaddr} uImage\0" \
	"loadirfs=fatload mmc ${mmcdev} ${rdaddr} rootfs.uboot\0" \
	"loadramdisk=fatload mmc ${mmcdev} ${rdaddr} ramdisk.gz\0" \
	"irfsboot=echo Booting from initramfs ...; run irfsargs; " \
		"bootm ${loadaddr} ${rdaddr}\0" \
	"ramboot=echo Booting from ramdisk.gz ...; run ramargs; " \
		"bootm ${loadaddr}\0" \
	"mmcboot=echo Booting from mmc ...; run mmcargs; bootm ${loadaddr}\0" \
	"nandboot=echo Booting from nand ...; run nandargs; " \
		"nand read ${loadaddr} 280000 400000; bootm ${loadaddr}\0" \
	"mtdparts=" MTDPARTS_DEFAULT "\0" \
	"stdout=serial,usbtty\0stdin=serial,usbtty\0stderr=serial,usbtty\0"
/*	"nandboot=echo Booting from nand ...; run nandargs; nboot kernel\0" */

#define CONFIG_BOOTCOMMAND \
	"if mmc rescan ${mmcdev}; then " \
	    "echo SD/MMC found on device ${mmcdev}; " \
	    "if run loadbootscript; then run bootscript; fi; " \
	    "if run loadbootenv; then " \
		"run importbootenv; " \
		"if test -n $uenvcmd; then " \
		    "echo Running uenvcmd ...; " \
		    "run uenvcmd; " \
		"fi; " \
	    "fi; " \
	    "if run loaduimage; then " \
		"if run loadirfs; then run irfsboot; fi; " \
		"if run loadramdisk; then run ramboot; fi; " \
		"run mmcboot; " \
	    "fi; " \
	"fi; " \
	"run nandboot; " \

#define CONFIG_AUTO_COMPLETE		1

/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP		/* undef to save memory, XXX: */
#define CONFIG_SYS_HUSH_PARSER		/* use "hush" command parser */
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#define CONFIG_SYS_PROMPT		"Beagle # "
#define CONFIG_SYS_CBSIZE		256	/* Console I/O Buffer Size */
/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + \
					sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS		16	/* max number of command args */
/* Boot Argument Buffer Size */
#define CONFIG_SYS_BARGSIZE		(CONFIG_SYS_CBSIZE)

#define CONFIG_SYS_MEMTEST_START	(OMAP34XX_SDRC_CS0)	/* memtest */
								/* works on */
#define CONFIG_SYS_MEMTEST_END		(OMAP34XX_SDRC_CS0 + \
					0x01F00000) /* 31MB */

#define CONFIG_SYS_LOAD_ADDR		(OMAP34XX_SDRC_CS0)	/* default */
							/* load address */

/*
 * OMAP3 has 12 GP timers, they can be driven by the system clock
 * (12/13/16.8/19.2/38.4MHz) or by 32KHz clock. We use 13MHz (V_SCLK).
 * This rate is divided by a local divisor.
 */
#define CONFIG_SYS_TIMERBASE		(OMAP34XX_GPT2)
#define CONFIG_SYS_PTV			2       /* Divisor: 2^(PTV+1) => 8 */
#define CONFIG_SYS_HZ			1000

/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE	(128 << 10)	/* regular stack 128 KiB */
#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ	(4 << 10)	/* IRQ stack 4 KiB */
#define CONFIG_STACKSIZE_FIQ	(4 << 10)	/* FIQ stack 4 KiB */
#endif

/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS	2	/* CS1 may or may not be populated */
#define PHYS_SDRAM_1		OMAP34XX_SDRC_CS0
#define PHYS_SDRAM_1_SIZE	(32 << 20)	/* at least 32 MiB */
#define PHYS_SDRAM_2		OMAP34XX_SDRC_CS1

/* SDRAM Bank Allocation method */
#define SDRC_R_B_C		1

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */

/* **** PISMO SUPPORT *** */

/* Configure the PISMO */
#define PISMO1_NAND_SIZE		GPMC_SIZE_128M
#define PISMO1_ONEN_SIZE		GPMC_SIZE_128M

#define CONFIG_SYS_MONITOR_LEN		(256 << 10)	/* Reserve 2 sectors */

#if defined(CONFIG_CMD_NAND)
#define CONFIG_SYS_FLASH_BASE		PISMO1_NAND_BASE
#endif

/* Monitor at start of flash */
#define CONFIG_SYS_MONITOR_BASE		CONFIG_SYS_FLASH_BASE
#define CONFIG_SYS_ONENAND_BASE		ONENAND_MAP

#define CONFIG_ENV_IS_IN_NAND		1
#define ONENAND_ENV_OFFSET		0x260000 /* environment starts here */
#define SMNAND_ENV_OFFSET		0x260000 /* environment starts here */

#define CONFIG_SYS_ENV_SECT_SIZE	(128 << 10)	/* 128 KiB */
#define CONFIG_ENV_OFFSET		SMNAND_ENV_OFFSET
#define CONFIG_ENV_ADDR			SMNAND_ENV_OFFSET

#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1
#define CONFIG_SYS_INIT_RAM_ADDR	0x4020f800
#define CONFIG_SYS_INIT_RAM_SIZE	0x800
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_INIT_RAM_ADDR + \
					 CONFIG_SYS_INIT_RAM_SIZE - \
					 GENERATED_GBL_DATA_SIZE)

#define CONFIG_OMAP3_SPI

#endif /* __CONFIG_H */
