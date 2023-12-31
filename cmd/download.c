/*
 * (C) Copyright 2019 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <common.h>
#include <command.h>
#include <console.h>

__weak void do_board_download(void)
{
}

static int do_download(struct cmd_tbl *cmdtp, int flag,
		       int argc, char *const argv[])
{
	disable_ctrlc(1);

	/* Allow board specific download, maybe noreturn */
	do_board_download();

	/* Generic download */
#ifdef CONFIG_CMD_ROCKUSB
	run_command("rockusb 0 $devtype $devnum", 0);
#endif
	printf("Enter rockusb failed, fallback to bootrom...\n");
	flush();
	run_command("rbrom", 0);

	return 0;
}

U_BOOT_CMD(
	download, 1, 1, do_download,
	"enter rockusb/bootrom download mode", ""
);
