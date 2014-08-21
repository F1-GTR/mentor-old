object MScan: TMScan
  Left = 532
  Top = 129
  Width = 392
  Height = 156
  Caption = 'Содержимое MTR файлов'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PrintScale = poNone
  Scaled = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 266
    Height = 13
    Caption = 'Папка, в которой будет произведено сканирование:'
  end
  object Label2: TLabel
    Left = 224
    Top = 72
    Width = 137
    Height = 29
    Caption = 'MTR Scanner'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsItalic]
    ParentFont = False
  end
  object Folder: TButton
    Left = 280
    Top = 24
    Width = 75
    Height = 17
    Caption = 'Сменить'
    TabOrder = 0
    OnClick = FolderClick
  end
  object Edit1: TEdit
    Left = 8
    Top = 24
    Width = 265
    Height = 21
    ReadOnly = True
    TabOrder = 1
  end
  object Button1: TButton
    Left = 8
    Top = 56
    Width = 201
    Height = 25
    Caption = 'Cканирование'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 88
    Width = 201
    Height = 25
    Caption = 'Результат сканирования'
    TabOrder = 3
    OnClick = Button2Click
  end
end
