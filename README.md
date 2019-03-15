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
<p> 1. Buat direktori dengan nama "hatiku" dengan mkdir</p>
<p> 2. Masuk ke folder "hatiku" dan buat file "elen.ku" dengan touch </p>
<p> 3. Buat code c dengan menggunakan daemon yang di sleep setiap 3 detik </p>
<p> isi code c: </p>
<p> a. masuk ke folder "hatiku"</p>
<p> b. membaca isi folder "hatiku", apakah ada file "elen.ku" atau tidak</p>
<p> c. jika ada, mengecek owner dan grup </p>
<p> d. Mengubah permission menjadi 777 dengan chmod</p>
<p> e. Menghapus file "elen.ku" dengan remove  </p>
<p>  Akhirnya kusuma bisa muvonn </p>



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
<p>1. Unzip file dengan melakukan proses exec</p>

```
         	char *un[3] = {"unzip","campur2.zip",NULL};
          	execv("/usr/bin/unzip",un);
```

<p>2. panggil fungsi pipe untuk membuka pipe tersebut. buat child untuk proses ke dua</p>

```
	pipe(file1);
    pipe(file2);
```

<p>3. pada proses di child, lakukan ls pada folder campur2 kita menggunakan file1[1] untuk menerima write output into buffer. Sehingga file1[0] dalam kondisi read</p>

```
			close(file1[0]);
            dup2(file1[1],STDOUT_FILENO);
            close(file1[1]);

	    execlp("ls","ls","campur2",NULL);
```

<p>4. buat child lagi untuk melakukan proses exec grep. file1[0] sebagai read into buffer di STDIN_FILENO. Selanjutnya, file2[1] menerima write outputnya. Lalu lakukan grep</p>

```
					close(file1[1]);
                	dup2(file1[0],STDIN_FILENO);
                	close(file1[0]);

                	close(file2[0]);
                	dup2(file2[1],STDOUT_FILENO);
                	close(file2[1]);


                	char *grep[]={"grep",".txt$", NULL};
                	execv("/bin/grep",grep);
```

<p>5. pada parent nya, taruh isi dari file2[0] ke data.txt dengan menggunakan fprintf </p>

```
			FILE* isifile=fdopen(file2[0],"r");
			FILE *daftar=fopen("daftar.txt","w");
			while(fgets(isi, sizeof(isi), isifile)!=NULL)
			{
				if(strstr(&isi[strlen(isi)-5],".txt")!=NULL)
				{
					fprintf(daftar,"%s",isi);
				}
			}
			
```

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
<p>1. membuat folder "makanan"</p>
<p>2. memasukan file "makan_enak.txt"</p>
<p>3. buat file c </p>
<p>a. membuat variabel waktu terakhir file "makan_enak.txt" dibuka, dan variabel waktu sekarang</p>
<p>b. jika selisih waktu tersebut kurang dari 30 jalankan step selanjutnya </p>
<p>c. buat variabel char "makan_sehat"</p>
<p>d. tambahkan "makan_sehat" dengan bilangan dan ".txt"</p>
<p>e. buat file dengan nama variabel yang sudah kita buat</p>
<p> selesai! berhasil diet!</p>
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
<p>5b. penghentian proses dengan menggunakan exec dengan perintah pkill</p>

```
execlp("pkill", "pkill", "-f", "soal5",NULL);
```
