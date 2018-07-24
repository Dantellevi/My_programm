object Form1: TForm1
  Left = 480
  Top = 0
  Caption = 'Form1'
  ClientHeight = 812
  ClientWidth = 1368
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 384
    Top = 777
    Width = 106
    Height = 19
    Caption = #1041#1072#1081#1090' '#1087#1088#1080#1085#1103#1090#1086':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 655
    Top = 776
    Width = 118
    Height = 19
    Caption = #1050#1086#1083'-'#1074#1086' '#1086#1096#1080#1073#1086#1082':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 935
    Top = 776
    Width = 120
    Height = 19
    Caption = #1050#1086#1083'-'#1074#1086' '#1087#1072#1082#1077#1090#1086#1074':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 8
    Top = 773
    Width = 161
    Height = 33
    Caption = #1054#1090#1082#1088#1099#1090#1100' COM-'#1087#1086#1088#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 496
    Top = 773
    Width = 153
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Text = #1095#1080#1089#1083#1086' '#1073#1072#1081#1090
  end
  object Edit2: TEdit
    Left = 776
    Top = 773
    Width = 153
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Text = #1054#1096#1080#1073#1082#1080
  end
  object Edit3: TEdit
    Left = 1061
    Top = 773
    Width = 153
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    Text = #1055#1072#1082#1077#1090#1099
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 1368
    Height = 767
    ActivePage = TabSheet2
    Align = alTop
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 4
    object TabSheet1: TTabSheet
      Caption = #1044#1072#1085#1085#1099#1077
      DoubleBuffered = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentDoubleBuffered = False
      ParentFont = False
      object MemoData: TMemo
        Left = 0
        Top = 0
        Width = 465
        Height = 576
        DoubleBuffered = True
        ParentDoubleBuffered = False
        ScrollBars = ssVertical
        TabOrder = 0
      end
      object MemoCount: TMemo
        Left = 471
        Top = 0
        Width = 465
        Height = 576
        DoubleBuffered = True
        ParentDoubleBuffered = False
        ScrollBars = ssVertical
        TabOrder = 1
      end
    end
    object График_2D_Дефекты: TTabSheet
      Caption = #1043#1088#1072#1092#1080#1082'_'#1040#1062#1055
      ImageIndex = 4
      object ChartADC: TChart
        Left = 0
        Top = 0
        Width = 1360
        Height = 739
        Legend.Visible = False
        Title.Color = 65408
        Title.Font.Color = clLime
        Title.Font.Height = -16
        Title.Font.Style = [fsBold]
        Title.Text.Strings = (
          'TChart')
        BottomAxis.LabelsFormat.Font.Color = clLime
        LeftAxis.Automatic = False
        LeftAxis.AutomaticMinimum = False
        LeftAxis.LabelsFormat.Font.Color = clLime
        LeftAxis.LabelsFormat.Font.Style = [fsBold]
        View3D = False
        Align = alClient
        Color = clBlack
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        PrintMargins = (
          15
          27
          15
          27)
        ColorPaletteIndex = 13
      end
    end
    object График_2D_Толщина: TTabSheet
      Caption = #1043#1088#1072#1092#1080#1082'_'#1062#1040#1055
      ImageIndex = 5
      object ChartDAC: TChart
        Left = 0
        Top = 0
        Width = 1360
        Height = 739
        Legend.Visible = False
        Title.Color = 65408
        Title.Font.Color = clLime
        Title.Font.Height = -16
        Title.Font.Style = [fsBold]
        Title.Text.Strings = (
          'TChart')
        BottomAxis.LabelsFormat.Font.Color = clLime
        LeftAxis.Automatic = False
        LeftAxis.AutomaticMinimum = False
        LeftAxis.LabelsFormat.Font.Color = clLime
        LeftAxis.LabelsFormat.Font.Style = [fsBold]
        View3D = False
        Align = alClient
        Color = clBlack
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        PrintMargins = (
          15
          27
          15
          27)
        ColorPaletteIndex = 13
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1062#1080#1092#1088#1086#1074#1099#1077'_'#1042#1067#1061#1054#1044#1067
      ImageIndex = 3
      ExplicitLeft = 8
      ExplicitTop = 28
      object ChartDOUT: TChart
        Left = 584
        Top = 0
        Width = 776
        Height = 736
        Legend.Visible = False
        Title.Color = 65408
        Title.Font.Color = clLime
        Title.Font.Height = -16
        Title.Font.Style = [fsBold]
        Title.Text.Strings = (
          'TChart')
        BottomAxis.LabelsFormat.Font.Color = clLime
        LeftAxis.Automatic = False
        LeftAxis.AutomaticMinimum = False
        LeftAxis.LabelsFormat.Font.Color = clLime
        LeftAxis.LabelsFormat.Font.Style = [fsBold]
        View3D = False
        Color = clBlack
        TabOrder = 12
        DefaultCanvas = 'TGDIPlusCanvas'
        PrintMargins = (
          15
          27
          15
          27)
        ColorPaletteIndex = 13
      end
      object ButtonDOut0: TButton
        Left = 4
        Top = 32
        Width = 161
        Height = 41
        Caption = #1053#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
        TabOrder = 0
        OnClick = ButtonDOutClick
      end
      object ButtonDOut1: TButton
        Left = 4
        Top = 72
        Width = 161
        Height = 41
        Caption = #1053#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
        TabOrder = 1
        OnClick = ButtonDOutClick
      end
      object ButtonDOut2: TButton
        Left = 4
        Top = 112
        Width = 161
        Height = 41
        Caption = #1053#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
        TabOrder = 2
        OnClick = ButtonDOutClick
      end
      object ButtonDOut3: TButton
        Left = 4
        Top = 152
        Width = 161
        Height = 41
        Caption = #1053#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
        TabOrder = 3
        OnClick = ButtonDOutClick
      end
      object ButtonDOut4: TButton
        Left = 4
        Top = 192
        Width = 161
        Height = 41
        Caption = #1053#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
        TabOrder = 4
        OnClick = ButtonDOutClick
      end
      object ButtonDOut5: TButton
        Left = 4
        Top = 232
        Width = 161
        Height = 41
        Caption = #1053#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
        TabOrder = 5
        OnClick = ButtonDOutClick
      end
      object ButtonDOut6: TButton
        Left = 4
        Top = 272
        Width = 161
        Height = 41
        Caption = #1053#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
        TabOrder = 6
        OnClick = ButtonDOutClick
      end
      object ButtonDOut7: TButton
        Left = 4
        Top = 312
        Width = 161
        Height = 41
        Caption = #1053#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
        TabOrder = 7
        OnClick = ButtonDOutClick
      end
      object ButtonDOut9: TButton
        Left = 4
        Top = 392
        Width = 161
        Height = 41
        Caption = #1053#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
        TabOrder = 9
        OnClick = ButtonDOutClick
      end
      object ButtonDOut10: TButton
        Left = 4
        Top = 432
        Width = 161
        Height = 41
        Caption = #1053#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
        TabOrder = 10
        OnClick = ButtonDOutClick
      end
      object ButtonDOut11: TButton
        Left = 4
        Top = 472
        Width = 161
        Height = 41
        Caption = #1053#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
        TabOrder = 11
        OnClick = ButtonDOutClick
      end
      object ButtonDOut8: TButton
        Left = 4
        Top = 352
        Width = 161
        Height = 41
        Caption = #1053#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
        TabOrder = 8
        OnClick = ButtonDOutClick
      end
    end
    object TabSheet3: TTabSheet
      Caption = #1062#1080#1092#1088#1086#1074#1099#1077'_'#1042#1061#1054#1044#1067
      ImageIndex = 4
      object ChartDIN: TChart
        Left = 0
        Top = 0
        Width = 1360
        Height = 739
        Legend.Visible = False
        Title.Color = 65408
        Title.Font.Color = clLime
        Title.Font.Height = -16
        Title.Font.Style = [fsBold]
        Title.Text.Strings = (
          'TChart')
        BottomAxis.LabelsFormat.Font.Color = clLime
        LeftAxis.Automatic = False
        LeftAxis.AutomaticMinimum = False
        LeftAxis.LabelsFormat.Font.Color = clLime
        LeftAxis.LabelsFormat.Font.Style = [fsBold]
        View3D = False
        Align = alClient
        Color = clBlack
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        PrintMargins = (
          15
          27
          15
          27)
        ColorPaletteIndex = 13
      end
    end
    object Калибровка: TTabSheet
      Caption = #1050#1072#1083#1080#1073#1088#1086#1074#1082#1072
      ImageIndex = 5
      object MemoAdcCalibr: TMemo
        Left = 3
        Top = 3
        Width = 238
        Height = 262
        TabOrder = 0
      end
      object MemoDacCalibr: TMemo
        Left = 247
        Top = 3
        Width = 238
        Height = 262
        TabOrder = 1
      end
      object ButtonCalibr: TButton
        Left = 3
        Top = 271
        Width = 482
        Height = 57
        Caption = #1042#1067#1063#1048#1058#1040#1058#1068
        TabOrder = 2
        OnClick = ButtonCalibrClick
      end
      object ButtonCodeToDac: TButton
        Left = 491
        Top = 3
        Width = 169
        Height = 49
        Caption = 'ButtonCodeToDac'
        TabOrder = 3
        OnClick = ButtonCodeToDacClick
      end
    end
    object Потоки: TTabSheet
      Caption = #1055#1086#1090#1086#1082#1080
      ImageIndex = 6
      object MemoPotoki: TMemo
        Left = 11
        Top = 11
        Width = 710
        Height = 262
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object TabSheet4: TTabSheet
      Caption = #1047#1040#1055#1059#1057#1050'_'#1059#1055#1056#1040#1042#1051#1045#1053#1048#1045
      ImageIndex = 7
      object PanelManeger: TPanel
        Left = 3
        Top = 3
        Width = 134
        Height = 134
        Caption = #1059#1055#1056#1040#1042#1051#1045#1053#1048#1045' '#1047#1040#1055#1059#1057#1050#1054#1052
        TabOrder = 0
        VerticalAlignment = taAlignTop
        object ButtonОК: TButton
          Left = 23
          Top = 24
          Width = 74
          Height = 41
          Caption = #1054#1050
          TabOrder = 0
          OnClick = ButtonOKClick
        end
        object ButtonКЦУ: TButton
          Left = 23
          Top = 71
          Width = 74
          Height = 41
          Caption = #1050#1062#1059
          TabOrder = 1
          OnClick = ButtonКЦУClick
        end
      end
      object PanelDout: TPanel
        Left = 3
        Top = 143
        Width = 134
        Height = 210
        Caption = #1062#1048#1060#1056#1054#1042#1067#1045' '#1042#1067#1061#1054#1044#1067
        TabOrder = 1
        VerticalAlignment = taAlignTop
        object MemoDout: TMemo
          Left = -3
          Top = 22
          Width = 137
          Height = 179
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 0
        end
      end
      object PanelDIn: TPanel
        Left = 3
        Top = 359
        Width = 134
        Height = 210
        Caption = #1062#1048#1060#1056#1054#1042#1067#1045' '#1042#1061#1054#1044#1067
        TabOrder = 2
        VerticalAlignment = taAlignTop
        object MemoDIn: TMemo
          Left = -3
          Top = 22
          Width = 137
          Height = 179
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 0
        end
      end
      object PanelAOut: TPanel
        Left = 143
        Top = 143
        Width = 134
        Height = 210
        Caption = #1040#1053#1040#1051#1054#1043#1054#1042#1067#1045' '#1042#1067#1061#1054#1044#1067
        TabOrder = 3
        VerticalAlignment = taAlignTop
        object MemoAOut: TMemo
          Left = -3
          Top = 22
          Width = 137
          Height = 179
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 0
        end
      end
      object PanelAin: TPanel
        Left = 143
        Top = 359
        Width = 134
        Height = 210
        Caption = #1040#1053#1040#1051#1054#1043#1054#1042#1067#1045' '#1042#1061#1054#1044#1067
        TabOrder = 4
        VerticalAlignment = taAlignTop
        object MemoAIn: TMemo
          Left = -3
          Top = 22
          Width = 137
          Height = 179
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 0
        end
      end
      object ChartФОН1: TChart
        Left = 296
        Top = 3
        Width = 1036
        Height = 170
        Legend.Visible = False
        Title.Color = 65408
        Title.Font.Color = clLime
        Title.Font.Height = -16
        Title.Font.Style = [fsBold]
        Title.Text.Strings = (
          #1060#1054#1053'1')
        BottomAxis.LabelsFormat.Font.Color = clLime
        LeftAxis.Automatic = False
        LeftAxis.AutomaticMinimum = False
        LeftAxis.LabelsFormat.Font.Color = clLime
        LeftAxis.LabelsFormat.Font.Style = [fsBold]
        View3D = False
        Color = clBlack
        TabOrder = 5
        DefaultCanvas = 'TGDIPlusCanvas'
        PrintMargins = (
          15
          27
          15
          27)
        ColorPaletteIndex = 13
        object SeriesФОН1: TLineSeries
          SeriesColor = clLime
          Brush.BackColor = clDefault
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
      object ChartДельтаЦУ: TChart
        Left = 296
        Top = 179
        Width = 1036
        Height = 170
        Legend.Visible = False
        Title.Color = 65408
        Title.Font.Color = clLime
        Title.Font.Height = -16
        Title.Font.Style = [fsBold]
        Title.Text.Strings = (
          #1044#1077#1083#1100#1090#1072#1062#1059)
        BottomAxis.LabelsFormat.Font.Color = clLime
        LeftAxis.Automatic = False
        LeftAxis.AutomaticMinimum = False
        LeftAxis.LabelsFormat.Font.Color = clLime
        LeftAxis.LabelsFormat.Font.Style = [fsBold]
        View3D = False
        Color = clBlack
        TabOrder = 6
        DefaultCanvas = 'TGDIPlusCanvas'
        PrintMargins = (
          15
          27
          15
          27)
        ColorPaletteIndex = 13
        object SeriesДельтаЦУ: TLineSeries
          SeriesColor = clLime
          Brush.BackColor = clDefault
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
      object ChartФ1: TChart
        Left = 296
        Top = 355
        Width = 1036
        Height = 170
        Legend.Visible = False
        Title.Color = 65408
        Title.Font.Color = clLime
        Title.Font.Height = -16
        Title.Font.Style = [fsBold]
        Title.Text.Strings = (
          #1060'1')
        BottomAxis.LabelsFormat.Font.Color = clLime
        LeftAxis.Automatic = False
        LeftAxis.AutomaticMinimum = False
        LeftAxis.LabelsFormat.Font.Color = clLime
        LeftAxis.LabelsFormat.Font.Style = [fsBold]
        View3D = False
        Color = clBlack
        TabOrder = 7
        DefaultCanvas = 'TGDIPlusCanvas'
        PrintMargins = (
          15
          27
          15
          27)
        ColorPaletteIndex = 13
        object SeriesФ1: TLineSeries
          SeriesColor = clLime
          Brush.BackColor = clDefault
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
      object ChartЗГ: TChart
        Left = 293
        Top = 531
        Width = 1036
        Height = 170
        Legend.Visible = False
        Title.Color = 65408
        Title.Font.Color = clLime
        Title.Font.Height = -16
        Title.Font.Style = [fsBold]
        Title.Text.Strings = (
          #1047#1072#1093#1074#1072#1090' '#1043#1086#1083#1086#1074#1082#1080
          '')
        BottomAxis.LabelsFormat.Font.Color = clLime
        LeftAxis.Automatic = False
        LeftAxis.AutomaticMinimum = False
        LeftAxis.LabelsFormat.Font.Color = clLime
        LeftAxis.LabelsFormat.Font.Style = [fsBold]
        View3D = False
        Color = clBlack
        TabOrder = 8
        DefaultCanvas = 'TGDIPlusCanvas'
        PrintMargins = (
          15
          27
          15
          27)
        ColorPaletteIndex = 13
        object SeriesЗГ: TLineSeries
          SeriesColor = clLime
          Brush.BackColor = clDefault
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
      object EditФI: TEdit
        Left = 3
        Top = 606
        Width = 134
        Height = 21
        TabOrder = 9
        Text = '0.0'
      end
      object EditФII: TEdit
        Left = 143
        Top = 606
        Width = 134
        Height = 21
        TabOrder = 10
        Text = '0.0'
      end
    end
  end
  object ApdComPort1: TApdComPort
    ComNumber = 2
    Baud = 921600
    InSize = 65000
    TraceName = 'APRO.TRC'
    LogName = 'APRO.LOG'
    OnPortOpen = ApdComPort1PortOpen
    OnTriggerAvail = ApdComPort1TriggerAvail
    Left = 1296
    Top = 776
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 300
    Left = 1240
    Top = 776
  end
end
