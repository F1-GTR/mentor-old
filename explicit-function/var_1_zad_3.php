<html><head>
    <meta http-equiv="Content-Type" content="text/html; charset=windows-1251">
<title>������� ��� ����������. </title>
<script type="text/javascript">
function dataSelect(f) { 
n = f.ask.selectedIndex
location.href = "../mod_prov.php?id_user=" + f.id_user.value + "&id_kurs=" + f.id_kurs.value + "&ask_numb=" + f.ask.options[n].value + "&level=3"
}
</script>
</head>
<body>
<form>
<?php
$id_kurs = $_GET[id_kurs];
$id_user = $_GET[id_user];
echo "<input type=\"hidden\" name=\"id_kurs\"  value=\"$id_kurs\" >\n";
echo "<input type=\"hidden\" name=\"id_user\"  value=\"$id_user\" >\n";
?>
������� �1:
<p>
<Img src= 'Image_1_zad_3.jpg' >
<p>
��� �����:
<p>
<select name="ask" onchange=""> 
<option value="1"> ������� a) </option>
<option value="2"> ������� b) </option>
<option value="3"> ������� c) </option>
<option value="4"> ������� d) </option>
</select>
<p>
<input type="button" value="��������" onClick="dataSelect(this.form)"> 
</form>
</body>
</html>
