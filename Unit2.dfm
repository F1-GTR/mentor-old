object PLAngle: TPLAngle
  Left = 252
  Top = 148
  Width = 609
  Height = 407
  Caption = 'Угол между прямой и плоскостью'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 569
    Height = 105
    Caption = 'Минимальные значения'
    TabOrder = 0
    object MinPoint: TTrackBar
      Left = 16
      Top = 32
      Width = 150
      Height = 45
      Max = 20
      Min = 1
      Orientation = trHorizontal
      Frequency = 1
      Position = 1
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = MinPointChange
    end
    object MinVector: TTrackBar
      Left = 200
      Top = 32
      Width = 150
      Height = 45
      Max = 20
      Min = 1
      Orientation = trHorizontal
      Frequency = 1
      Position = 1
      SelEnd = 0
      SelStart = 0
      TabOrder = 1
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = MinVectorChange
    end
    object MinPlate: TTrackBar
      Left = 392
      Top = 32
      Width = 150
      Height = 45
      Max = 20
      Min = 1
      Orientation = trHorizontal
      Frequency = 1
      Position = 1
      SelEnd = 0
      SelStart = 0
      TabOrder = 2
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = MinPlateChange
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 120
    Width = 569
    Height = 105
    Caption = 'Максимальные значения'
    TabOrder = 1
    object MaxPoint: TTrackBar
      Left = 16
      Top = 32
      Width = 150
      Height = 45
      Max = 20
      Min = 1
      Orientation = trHorizontal
      Frequency = 1
      Position = 1
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = MaxPointChange
    end
    object MaxVector: TTrackBar
      Left = 200
      Top = 32
      Width = 150
      Height = 45
      Max = 20
      Min = 1
      Orientation = trHorizontal
      Frequency = 1
      Position = 1
      SelEnd = 0
      SelStart = 0
      TabOrder = 1
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = MaxVectorChange
    end
    object MaxPlate: TTrackBar
      Left = 392
      Top = 32
      Width = 150
      Height = 45
      Max = 20
      Min = 1
      Orientation = trHorizontal
      Frequency = 1
      Position = 1
      SelEnd = 0
      SelStart = 0
      TabOrder = 2
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = MaxPlateChange
    end
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 232
    Width = 185
    Height = 81
    Caption = 'Точка'
    TabOrder = 2
    object Point: TLabel
      Left = 72
      Top = 32
      Width = 24
      Height = 13
      Caption = 'Point'
    end
  end
  object GroupBox4: TGroupBox
    Left = 200
    Top = 232
    Width = 185
    Height = 81
    Caption = 'Вектор'
    TabOrder = 3
    object Vector: TLabel
      Left = 72
      Top = 32
      Width = 31
      Height = 13
      Caption = 'Vector'
    end
  end
  object GroupBox5: TGroupBox
    Left = 392
    Top = 232
    Width = 185
    Height = 81
    Caption = 'Плоскость'
    TabOrder = 4
    object Plate: TLabel
      Left = 72
      Top = 32
      Width = 24
      Height = 13
      Caption = 'Plate'
    end
  end
  object Save: TButton
    Left = 184
    Top = 328
    Width = 75
    Height = 25
    Caption = 'Сохранить'
    TabOrder = 5
    OnClick = SaveClick
  end
  object Cancel: TButton
    Left = 272
    Top = 328
    Width = 75
    Height = 25
    Caption = 'Отмена'
    TabOrder = 6
    OnClick = CancelClick
  end
end
