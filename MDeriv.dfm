object FDeriv: TFDeriv
  Left = 205
  Top = 202
  Width = 619
  Height = 443
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  Caption = 'FDeriv'
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 28
    Top = 36
    Width = 53
    Height = 13
    Caption = 'Диапазон:'
  end
  object Bevel1: TBevel
    Left = -16
    Top = 368
    Width = 661
    Height = 5
    Shape = bsTopLine
  end
  object Label5: TLabel
    Left = 92
    Top = 16
    Width = 16
    Height = 13
    Caption = 'min'
  end
  object Label6: TLabel
    Left = 128
    Top = 16
    Width = 20
    Height = 13
    Caption = 'max'
  end
  object Label24: TLabel
    Left = 24
    Top = 68
    Width = 124
    Height = 13
    Caption = 'Тип производной (1-12):'
  end
  object Memo1: TMemo
    Left = 212
    Top = 16
    Width = 381
    Height = 337
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object rmin: TEdit
    Left = 88
    Top = 32
    Width = 29
    Height = 21
    TabOrder = 1
  end
  object Button1: TButton
    Left = 304
    Top = 380
    Width = 69
    Height = 25
    Caption = 'Генерация'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 456
    Top = 380
    Width = 69
    Height = 25
    Caption = 'Принять'
    Default = True
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 532
    Top = 380
    Width = 69
    Height = 25
    Cancel = True
    Caption = 'Отмена'
    TabOrder = 4
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 380
    Top = 380
    Width = 69
    Height = 25
    Caption = 'Просмотр'
    TabOrder = 5
    OnClick = Button4Click
  end
  object GroupBox1: TGroupBox
    Left = 20
    Top = 244
    Width = 177
    Height = 109
    Caption = ' Режим генерации ключа '
    TabOrder = 6
    object Label3: TLabel
      Left = 24
      Top = 56
      Width = 28
      Height = 13
      Caption = 'Ключ'
    end
    object Label4: TLabel
      Left = 80
      Top = 56
      Width = 42
      Height = 13
      Caption = 'Вариант'
    end
    object RadioButton1: TRadioButton
      Left = 12
      Top = 20
      Width = 137
      Height = 17
      Caption = 'Автоматическая'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 12
      Top = 36
      Width = 129
      Height = 17
      Caption = 'Ручная генерация'
      TabOrder = 1
      OnClick = RadioButton2Click
    end
    object Edit3: TEdit
      Left = 16
      Top = 72
      Width = 53
      Height = 21
      Enabled = False
      TabOrder = 2
      Text = '0'
    end
    object Edit4: TEdit
      Left = 76
      Top = 72
      Width = 53
      Height = 21
      Enabled = False
      TabOrder = 3
      Text = '1'
    end
  end
  object rmax: TEdit
    Left = 124
    Top = 32
    Width = 29
    Height = 21
    TabOrder = 7
  end
  object etype: TEdit
    Left = 20
    Top = 84
    Width = 177
    Height = 21
    TabOrder = 8
    Text = 'etype'
  end
end
