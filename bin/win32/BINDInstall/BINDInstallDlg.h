/*
 * Copyright (C) Internet Systems Consortium, Inc. ("ISC")
 *
 * SPDX-License-Identifier: MPL-2.0
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0.  If a copy of the MPL was not distributed with this
 * file, you can obtain one at https://mozilla.org/MPL/2.0/.
 *
 * See the COPYRIGHT file distributed with this work for additional
 * information regarding copyright ownership.
 */

/*
 * Copyright (c) 1999-2000 by Nortel Networks Corporation
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND NORTEL NETWORKS DISCLAIMS
 * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL NORTEL NETWORKS
 * BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES
 * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 */

#ifndef BINDINSTALLDLG_H
#define BINDINSTALLDLG_H

class CBINDInstallDlg : public CDialog {
      public:
	CBINDInstallDlg(CWnd *pParent = NULL); /* standard constructor */

	/*{{AFX_DATA(CBINDInstallDlg) */
	enum { IDD = IDD_BINDINSTALL_DIALOG };
	CString m_targetDir;
	CString m_version;
	BOOL m_autoStart;
	BOOL m_keepFiles;
	BOOL m_toolsOnly;
	CString m_current;
	BOOL m_startOnInstall;
	/*}}AFX_DATA */

	/* ClassWizard generated virtual function overrides */
	/*{{AFX_VIRTUAL(CBINDInstallDlg) */
      protected:
	virtual void
	DoDataExchange(CDataExchange *pDX); /* DDX/DDV support */
					    /*}}AFX_VIRTUAL */

      protected:
	void
	StartBINDService();
	void
	StopBINDService();

	void
	InstallTags();
	void
	UninstallTags();

	void
	CreateDirs();
	void
	RemoveDirs(BOOL uninstall);

	void
	ReadInstallFlags();
	void
	ReadInstallFileList();

	void
	CopyFiles();
	void
	DeleteFiles(BOOL uninstall);

	void
	RegisterService();
	void
	UpdateService(CString StartName);
	void
	UnregisterService(BOOL uninstall);

	void
	RegisterMessages();
	void
	UnregisterMessages(BOOL uninstall);

	void
	FailedInstall();
	void
	SetItemStatus(UINT nID, BOOL bSuccess = TRUE);

	void
	GetCurrentServiceAccountName();
	BOOL
	ValidateServiceAccount();

      protected:
	CString
	DestDir(int destination);
	int
	MsgBox(int id, ...);
	int
	MsgBox(int id, UINT type, ...);
	CString
	GetErrMessage(DWORD err = -1);
	BOOL
	CheckBINDService();
	void
	SetCurrent(int id, ...);
	void
	ProgramGroup(BOOL create = TRUE);
	void
	ProgramGroupCreate(TCHAR *commonPath);
	void
	ProgramGroupRemove(TCHAR *commonPath);

	HICON m_hIcon;
	CString m_defaultDir;
	CString m_etcDir;
	CString m_binDir;
	CString m_winSysDir;
	BOOL m_installed;
	CString m_currentDir;
	BOOL m_accountExists;
	BOOL m_accountUsed;
	CString m_currentAccount;
	CString m_accountName;
	CString m_accountPasswordConfirm;
	CString m_accountPassword;
	BOOL m_serviceExists;

	/* Generated message map functions */
	/*{{AFX_MSG(CBINDInstallDlg) */
	virtual BOOL
	OnInitDialog();
	afx_msg void
	OnPaint();
	afx_msg HCURSOR
	OnQueryDragIcon();
	afx_msg void
	OnBrowse();
	afx_msg void
	OnChangeTargetdir();
	afx_msg void
	OnInstall();
	afx_msg void
	OnExit();
	afx_msg void
	OnUninstall();
	afx_msg void
	OnAutoStart();
	afx_msg void
	OnKeepFiles();
	afx_msg void
	OnStartOnInstall();
	/*}}AFX_MSG */
	DECLARE_MESSAGE_MAP()
};

#endif /* ifndef BINDINSTALLDLG_H */
