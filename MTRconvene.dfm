object FMTRconv: TFMTRconv
  Left = 99
  Top = 112
  Width = 568
  Height = 529
  Caption = 'Утилита слияния MTRconv'
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
  object Splitter2: TSplitter
    Left = 141
    Top = 109
    Width = 3
    Height = 324
    Cursor = crHSplit
    Beveled = True
  end
  object Bevel1: TBevel
    Left = 0
    Top = 61
    Width = 560
    Height = 4
    Align = alTop
    Shape = bsTopLine
  end
  object files: TListView
    Left = 144
    Top = 109
    Width = 404
    Height = 324
    Align = alClient
    Columns = <
      item
        Caption = 'Имя файла'
        Width = 150
      end
      item
        Caption = 'Путь'
        Width = 250
      end>
    GridLines = True
    HideSelection = False
    MultiSelect = True
    RowSelect = True
    TabOrder = 0
    ViewStyle = vsReport
    OnDblClick = filesDblClick
    OnMouseDown = filesMouseDown
    OnMouseMove = filesMouseMove
  end
  object Panel1: TPanel
    Left = 0
    Top = 65
    Width = 560
    Height = 44
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object Label1: TLabel
      Left = 16
      Top = 8
      Width = 532
      Height = 26
      Caption = 
        '       Чтобы объединить несколько MTR-файлов, перетащите их в сп' +
        'исок, упорядочите, затем нажмите "Объединить" и введите имя резу' +
        'льтирующего файла.'
      WordWrap = True
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 109
    Width = 141
    Height = 324
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
    object Panel7: TPanel
      Left = 13
      Top = 0
      Width = 128
      Height = 324
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 0
      object Panel8: TPanel
        Left = 0
        Top = 0
        Width = 128
        Height = 21
        Align = alTop
        BevelOuter = bvNone
        Caption = 'Panel6'
        TabOrder = 0
        OnConstrainedResize = Panel8ConstrainedResize
        object DriveComboBox1: TDriveComboBox
          Left = 0
          Top = 0
          Width = 165
          Height = 19
          TabOrder = 0
          OnChange = DriveComboBox1Change
        end
      end
      object Panel9: TPanel
        Left = 0
        Top = 21
        Width = 128
        Height = 303
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 1
        object Splitter1: TSplitter
          Left = 0
          Top = 89
          Width = 128
          Height = 3
          Cursor = crVSplit
          Align = alTop
          Beveled = True
        end
        object DirectoryListBox1: TDirectoryListBox
          Left = 0
          Top = 0
          Width = 128
          Height = 89
          Align = alTop
          ItemHeight = 16
          TabOrder = 0
          OnChange = DirectoryListBox1Change
        end
        object FileListBox1: TFileListBox
          Left = 0
          Top = 92
          Width = 128
          Height = 211
          Align = alClient
          ItemHeight = 13
          Mask = '*.mtr'
          TabOrder = 1
          OnDblClick = FileListBox1DblClick
        end
      end
    end
    object Panel11: TPanel
      Left = 0
      Top = 0
      Width = 13
      Height = 324
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 1
    end
  end
  object Panel3: TPanel
    Left = 548
    Top = 109
    Width = 12
    Height = 324
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel4: TPanel
    Left = 0
    Top = 433
    Width = 560
    Height = 69
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 4
    object Bevel2: TBevel
      Left = 0
      Top = 17
      Width = 560
      Height = 5
      Align = alTop
      Shape = bsTopLine
    end
    object Panel5: TPanel
      Left = 328
      Top = 22
      Width = 232
      Height = 47
      Align = alRight
      BevelOuter = bvNone
      TabOrder = 0
      object BitBtn1: TBitBtn
        Left = 120
        Top = 8
        Width = 101
        Height = 29
        Caption = '&Объединить'
        TabOrder = 0
        OnClick = BitBtn1Click
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          04000000000000010000130B0000130B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333303
          333333333333337FF3333333333333903333333333333377FF33333333333399
          03333FFFFFFFFF777FF3000000999999903377777777777777FF0FFFF0999999
          99037F3337777777777F0FFFF099999999907F3FF777777777770F00F0999999
          99037F773777777777730FFFF099999990337F3FF777777777330F00FFFFF099
          03337F773333377773330FFFFFFFF09033337F3FF3FFF77733330F00F0000003
          33337F773777777333330FFFF0FF033333337F3FF7F3733333330F08F0F03333
          33337F7737F7333333330FFFF003333333337FFFF77333333333000000333333
          3333777777333333333333333333333333333333333333333333}
        NumGlyphs = 2
      end
      object BitBtn2: TBitBtn
        Left = 16
        Top = 8
        Width = 101
        Height = 29
        Caption = 'О&тменить'
        TabOrder = 1
        OnClick = BitBtn2Click
        Kind = bkCancel
      end
    end
    object Panel10: TPanel
      Left = 0
      Top = 0
      Width = 560
      Height = 17
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 1
    end
    object BitBtn3: TBitBtn
      Left = 12
      Top = 30
      Width = 101
      Height = 29
      Caption = '&Справка'
      TabOrder = 2
      Kind = bkHelp
    end
  end
  object Panel6: TPanel
    Left = 0
    Top = 0
    Width = 560
    Height = 61
    Align = alTop
    BevelOuter = bvNone
    Color = clWindow
    TabOrder = 5
    object Image1: TImage
      Left = 16
      Top = 12
      Width = 32
      Height = 32
      AutoSize = True
      Picture.Data = {
        055449636F6E0000010001002020100000000000E80200001600000028000000
        2000000040000000010004000000000080020000000000000000000000000000
        0000000000000000000080000080000000808000800000008000800080800000
        80808000C0C0C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000
        FFFFFF0000000000000000000000000000000000000000000000000000000000
        0000000000000000000008888800000000000000000000000008844444880000
        0000000000000000008447777744800000000000000000000844444444444800
        0000000000000000844444444444448000000000000000008444444444444480
        000000000000000844444E444444444800000000000000084444E44444444448
        0000000000000008444E6E44444444480000000000000008444CECECCCCC4448
        00000000000000084CCE6ECCCCCCCC4800000000000000008CCCE6ECCCCCCC80
        000000000000000088FCCECCCCCCF8800000000000000000088F8F8F8F8F8800
        00000000000000000088FFF8F8F88000000000000000000000088FFF8F880000
        0000000000000000000088FFF8800000000000000000000000007F8F8F700000
        0000000000000000000008FFF800000000000000000000000000088F88000000
        0000000000000000000008FFF800000000000000000000000000088F88000000
        0000000000000000000008FFF800000000000000000000000000088F88000000
        0000000000000000000008F87700000000000000000000000007888888870000
        0000000000000000000887777788000000000000000000000007788888770000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000FFFFFFFFFFF83FFFFFE00FFFFFC007FFFF8003FFFF0001FFFE0000FF
        FE0000FFFC00007FFC00007FFC00007FFC00007FFC00007FFE0000FFFE0000FF
        FF0001FFFF8003FFFFC007FFFFE00FFFFFE00FFFFFF01FFFFFF01FFFFFF01FFF
        FFF01FFFFFF01FFFFFF01FFFFFE00FFFFFC007FFFFC007FFFFC007FFFFE00FFF
        FFFFFFFF}
    end
    object Label2: TLabel
      Left = 52
      Top = 12
      Width = 84
      Height = 25
      Caption = 'MTRconv'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 56
      Top = 32
      Width = 180
      Height = 13
      Caption = 'Утилита объединения MTR-файлов'
      Transparent = True
    end
  end
  object savedlg: TSaveDialog
    Options = [ofOverwritePrompt, ofHideReadOnly, ofPathMustExist, ofNoTestFileCreate, ofEnableSizing]
    Left = 284
    Top = 20
  end
end
