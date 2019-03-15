<h3>NOMOR 1</h3>
<h4>SOAL</h4>
<p>Elen mempunyai pekerjaan pada studio sebagai fotografer. Suatu hari ada seorang klien yang bernama Kusuma yang meminta untuk mengubah nama file yang memiliki ekstensi .png menjadi “[namafile]_grey.png”. Karena jumlah file yang diberikan Kusuma tidak manusiawi, maka Elen meminta bantuan kalian untuk membuat suatu program C yang dapat mengubah nama secara otomatis dan diletakkan pada direktori /home/[user]/modul2/gambar.
Catatan : Tidak boleh menggunakan crontab.</p>

<h4>PENJELASAN</h4>
<p>1. Awalnya kita harus membuat dulu folder modul2 dan di dalam folder modul2 ada folder gambar. Sebelum kita membuat folder tersebut, kita cek sudah atau belum folder tersebut.</p>
```
    if (stat("modul2", &st) == -1) {
        mkdir("modul2",0777);
        mkdir("modul2/gambar", 0777);

    }
```
<p>2. Buka folder yang berisi gambar dengan menggunakan fungsi opendir</p>
```
	folder = opendir("/home/safhiram/foldergambar");
```
<p>3. Baca file yang ada di folder tersebut dengan menggunakan readdir</p>
```
	rent=readdir(folder))
```
<p>4. buat string yang berisi tempat folder yang dituju dan asalnya untuk digunakan pada saat memindah file. Sekaligus string untuk menyimpan nama  file</p>
```
    strcpy(from, "/home/safhiram/foldergambar/");
    strcpy(dest,"/home/safhiram/modul2/gambar/");
```
<p>5.Jika nama mengandung .png maka pada namafile akan ditambah _grey.png. sekaligus dipindahkan ke folder tujuan dari folder asal</p>
```
 	strcat(from,nama);
    strncpy(namafile,nama,jumlah-4);
    strcat(namafile,"_grey.png");
    strcat(dest,namafile);
    printf("%s %s\n",from,dest);
    rename(from,dest);
```