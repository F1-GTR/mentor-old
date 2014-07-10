object MEigen: TMEigen
  Left = 278
  Top = 138
  Width = 541
  Height = 352
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  Caption = 'MEigen'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 12
    Top = 16
    Width = 140
    Height = 13
    Caption = 'Порядок матрицы (2 или 3):'
  end
  object Label2: TLabel
    Left = 12
    Top = 64
    Width = 135
    Height = 13
    Caption = 'Кол-во различных собств.:'
  end
  object Bevel1: TBevel
    Left = -16
    Top = 280
    Width = 561
    Height = 5
    Shape = bsTopLine
  end
  object Memo1: TMemo
    Left = 188
    Top = 12
    Width = 337
    Height = 257
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 8
    Top = 32
    Width = 169
    Height = 21
    TabOrder = 1
  end
  object Edit2: TEdit
    Left = 8
    Top = 80
    Width = 169
    Height = 21
    TabOrder = 2
  end
  object Button1: TButton
    Left = 228
    Top = 292
    Width = 69
    Height = 25
    Caption = 'Генерация'
    TabOrder = 3
  end
  object Button2: TButton
    Left = 380
    Top = 292
    Width = 69
    Height = 25
    Caption = 'Принять'
    Default = True
    TabOrder = 4
  end
  object Button3: TButton
    Left = 456
    Top = 292
    Width = 69
    Height = 25
    Cancel = True
    Caption = 'Отмена'
    TabOrder = 5
  end
  object Button4: TButton
    Left = 304
    Top = 292
    Width = 69
    Height = 25
    Caption = 'Просмотр'
    TabOrder = 6
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 160
    Width = 169
    Height = 109
    Caption = ' Режим генерации ключа '
    TabOrder = 7
    object Label3: TLabel
      Left = 24
      Top = 56
      Width = 26
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
    end
    object RadioButton2: TRadioButton
      Left = 12
      Top = 36
      Width = 129
      Height = 17
      Caption = 'Ручная генерация'
      TabOrder = 1
    end
    object Edit3: TEdit
      Left = 16
      Top = 72
      Width = 53
      Height = 21
      Enabled = False
      TabOrder = 2
    end
    object Edit4: TEdit
      Left = 76
      Top = 72
      Width = 53
      Height = 21
      Enabled = False
      TabOrder = 3
    end
  end
end
