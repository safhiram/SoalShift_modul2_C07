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

<p>4. buat string yang berisi tempat folder yang dituju dan asalnya untuk 
digunakan pada saat memindah file. Sekaligus string untuk menyimpan nama  file</p>

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


<hr>
<h3>NOMOR 2</h3>
<h4>SOAL</h4>
<p>Pada suatu hari Kusuma dicampakkan oleh Elen karena Elen dimenangkan oleh orang lain. Semua kenangan tentang Elen berada pada file bernama “elen.ku” pada direktori “hatiku”. Karena sedih berkepanjangan, tugas kalian sebagai teman Kusuma adalah membantunya untuk menghapus semua kenangan tentang Elen dengan membuat program C yang bisa mendeteksi owner dan group dan menghapus file “elen.ku” setiap 3 detik dengan syarat ketika owner dan grupnya menjadi “www-data”. Ternyata kamu memiliki kendala karena permission pada file “elen.ku”. Jadi, ubahlah permissionnya menjadi 777. Setelah kenangan tentang Elen terhapus, maka Kusuma bisa move on.
Catatan: Tidak boleh menggunakan crontab</p>
<h4>PENJELASAN</h4>

<hr>
<h3>NOMOR 3</h3>
<h4>SOAL</h4>
<p>Diberikan file campur2.zip. Di dalam file tersebut terdapat folder “campur2”. 
Buatlah program C yang dapat :
i)  mengekstrak file zip tersebut.
ii) menyimpan daftar file dari folder “campur2” yang memiliki ekstensi .txt ke dalam file daftar.txt. 
Catatan:  
Gunakan fork dan exec.
Gunakan minimal 3 proses yang diakhiri dengan exec.
Gunakan pipe
Pastikan file daftar.txt dapat diakses dari text editor
</p>
<h4>PENJELASAN</h4>

<hr>
<h3>NOMOR 4</h3>
<h4>SOAL</h4>
<p>Dalam direktori /home/[user]/Documents/makanan terdapat file makan_enak.txt yang berisikan daftar makanan terkenal di Surabaya. Elen sedang melakukan diet dan seringkali tergiur untuk membaca isi makan_enak.txt karena ngidam makanan enak. Sebagai teman yang baik, Anda membantu Elen dengan membuat program C yang berjalan setiap 5 detik untuk memeriksa apakah file makan_enak.txt pernah dibuka setidaknya 30 detik yang lalu (rentang 0 - 30 detik).
Jika file itu pernah dibuka, program Anda akan membuat 1 file makan_sehat#.txt di direktori /home/[user]/Documents/makanan dengan '#' berisi bilangan bulat dari 1 sampai tak hingga untuk mengingatkan Elen agar berdiet.

Contoh:
File makan_enak.txt terakhir dibuka pada detik ke-1
Pada detik ke-10 terdapat file makan_sehat1.txt dan makan_sehat2.txt

Catatan: 
dilarang menggunakan crontab
Contoh nama file : makan_sehat1.txt, makan_sehat2.txt, dst
</p>
<h4>PENJELASAN</h4>

<hr>
<h3>NOMOR 5</h3>
<h4>SOAL</h4>
<p>Kerjakan poin a dan b di bawah:
Buatlah program c untuk mencatat log setiap menit dari file log pada syslog ke /home/[user]/log/[dd:MM:yyyy-hh:mm]/log#.log
Ket:
Per 30 menit membuat folder /[dd:MM:yyyy-hh:mm]
Per menit memasukkan log#.log ke dalam folder tersebut
‘#’ : increment per menit. Mulai dari 1
Buatlah program c untuk menghentikan program di atas.
NB: Dilarang menggunakan crontab dan tidak memakai argumen ketika menjalankan program.
</p>
<h4>PENJELASAN</h4>
<p>1. Awalnya kita harus menyimpan nilai dari waktu sekarang</p>

```
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
```

<p>2. simpan nama folder yang akan dibuat dan buat folder log</p>

```
snprintf(namafile, sizeof(namafile), "/home/safhiram/log/%02d:%02d:%04d-%02d:%02d", tm.tm_mday,tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);

mkdir("/home/safhiram/log",0777);

```

<p>3. simpan nama file yang akan dibuat. lakukan proses exec untuk menyalin file dari /var/log/syslol ke folder yang tadi dibuat</p>

```
	snprintf(hehe, sizeof(hehe), "/home/safhiram/log/%02d:%02d:%04d-%02d:%02d/", tm.tm_mday,tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);	
			snprintf(tambahan,sizeof(tambahan),"log%d.log",i);
			strcat(hehe,tambahan);
			if(fork()==0)
			{
				execlp("cp","cp","/var/log/syslog", hehe, NULL);
			}

```

<p>4. jika file sudah lebih dari 30 atau sudah 30 menit berjalan, maka buat folder baru.</p>

```
			if(i > 30)
			{
				i=1;
				t=time(NULL);
				tm = *localtime(&t);
				snprintf(namafile, sizeof(namafile), "/home/safhiram/log/%02d:%02d:%04d-%02d:%02d", tm.tm_mday,tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
				mkdir(namafile,0777);
				
			}
```