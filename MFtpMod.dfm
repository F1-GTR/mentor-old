object FtpMod: TFtpMod
  Left = 249
  Top = 217
  Width = 402
  Height = 218
  Caption = 'Соединение по ftp'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 0
    Top = 0
    Width = 32
    Height = 13
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 200
    Top = 0
    Width = 32
    Height = 13
    Caption = 'Label2'
  end
  object Button1: TButton
    Left = 56
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 264
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 1
    OnClick = Button2Click
  end
  object ListBox1: TListBox
    Left = 0
    Top = 16
    Width = 201
    Height = 129
    ItemHeight = 13
    TabOrder = 2
  end
  object ListBox2: TListBox
    Left = 200
    Top = 16
    Width = 193
    Height = 129
    ItemHeight = 13
    MultiSelect = True
    TabOrder = 3
    OnDblClick = ListBox2DblClick
  end
  object NMFTP1: TNMFTP
    Port = 21
    ReportLevel = 0
    Vendor = 2411
    ParseList = False
    ProxyPort = 0
    Passive = False
    FirewallType = FTUser
    FWAuthenticate = False
    Left = 216
    Top = 64
  end
end
