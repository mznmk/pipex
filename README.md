# Pipex

C言語で 42-pipex をつくってみた  
[![](https://img.youtube.com/vi/xpVkqRyrKPY/0.jpg)](https://www.youtube.com/watch?v=xpVkqRyrKPY)  

C言語で 42-pipex をつくってみた (here_doc実装編)  
[![](https://img.youtube.com/vi/lIvp3lHBWrw/0.jpg)](https://www.youtube.com/watch?v=lIvp3lHBWrw)

Summary:  
This project will let you discover in detail a UNIX mechanism that you already know
by using it in your program.  


### 42 old curriculum

Pipex once existed as Rush Project  

### 42 new curriculum

Pipex now exists as Cursus 1stCircle Level2 Project  


## [ pipex ] 実行ファイル作成方法

```sh
make			// pipex (mandatory) のコンパイルが実行されます
make pipex		// pipex (mandatory) のコンパイルが実行されます
make bonus		// pipex (bonus) のコンパイルが実行されます
```

## [ pipex ] 実行方法

- 凡例  
	infile: 入力元ファイル  
	outfile: 出力先ファイル  
	command1: １番目に実行されるコマンド  
	command2: ２番目に実行されるコマンド  
	commandN: Ｎ番目に実行されるコマンド  
	LIMITER: here_docの区切り文字列  

- ./pipex (mandatory)  
	```sh
	< infile "command1" | "command2" > outfile
	```
	この挙動を`./pipex`で再現するには次のコマンドを実行します。  
	```sh
	./pipex infile "command1" "command2" outfile
	# ----- example ----- #
	./pipex files/infile.txt "grep aa" "wc -w" file/outfile.txt		# (ex1)
	```
	(ex1):  
	`infile.txt`から入力を受け取り、`grep aa` `wc -w` を実行した結果を`outfile.txt`に出力（上書き）します。  

- ./pipex (bonus)  
	```sh
	< infile "command1" | "command2" | ... | "commandN" > outfile
	```
	この挙動を`./pipex_bonus`で再現するには次のコマンドを実行します。  
	```sh
	./pipex_bonus infile "command1" "command2" ... "commandN" outfile
	# ----- example ----- #
	./pipex_bonus files/infile.txt "grep aa" "grep xx" "grep yy" "grep zz" "grep bb" "wc -w" files/outfile.txt	# (ex2)
	```
	(ex2):  
	`infile.txt`から入力を受け取り、`grep aa` `grep xx` `grep yy` `grep zz` `grep bb` `wc -w` を実行した結果を`outfile.txt`に出力（上書き）します。  

	```sh
	"command1" << LIMITER | "command2" | ... | "commandN" >> outfile
	```
	この挙動を`./pipex_bonus`で再現するには次のコマンドを実行します。  
	```sh
	./pipex_bonus here_doc "LIMITER" "command1" "command2" ... "commandN" outfile
	# ----- example ----- #
	./pipex_bonus here_doc "EOF" "grep aa" "grep bb" files/outfile.txt	# (ex3)
	```
	(ex3):  
	コマンドを実行すると、`here_doc`の入力を待ち受けます。"EOF"という文字列を受け付けるまで待ち受けは続きます。`here_doc`を入力として、`grep aa` `grep bb` を実行した結果を`outfile.txt`に出力（追記）します。  


## [ sample ] 実行ファイル作成方法

```sh
make p0c1		// sample (pipe==0; command==1;) のコンパイルが実行されます
make p1c2		// sample (pipe==1; command==2;) のコンパイルが実行されます
make p2p3		// sample (pipe==command-1; 1<=command<=6;) のコンパイルが実行されます
```

## [ sample ] 実行方法

- 凡例  
	infile: 入力元ファイル  
	outfile: 出力先ファイル  
	command1: １番目に実行されるコマンド  
	command2: ２番目に実行されるコマンド  
	commandN: Ｎ番目に実行されるコマンド  
	LIMITER: here_docの区切り文字列  

- ./p0c1  
	サンプルコード１です。本当にシンプルなものです。  
	プロセスの入力元にファイルを繋げ、コマンドを実行するだけのものです。  
	プロセスの出力先は変更していませんので、標準出力のままとなります。  
	
	実行コマンドはこちらです。  
	```sh
	./p0c1 files/infile.txt
	```
	次のコマンドと同じ挙動となります。  
	```sh
	< files/infile.txt wc -w
	```

- ./p1c2  
	サンプルコード２です。パイプを使った処理を行ってみます。  
	２つのプロセスを１本のパイプで繋げて、プロセス同士のデータのやり取りをします。コマンドの実行回数は２回です。  
	最初のプロセスの入力元にファイルを繋げ、出力先にはパイプの入口を繋ぎます。コマンドを実行すると、パイプを通じて実行結果を２番目のプロセスに流します。  
	２番目のプロセスの入力先にパイプの出口を繋ぎ、出力先にはファイルを繋ぎます。コマンドを実行すると、パイプを通じて最初のプロセスでの実行結果を受け取り、コマンドの実行結果をファイルに流します。  

	```sh
	./p1c2 files/infile.txt files/outfile.txt
	```
	次のコマンドと同じ挙動となります。  
	```sh
	< files/infile.txt grep aa | wc -w > files/outfile.txt
	```

- ./p2c3  
	サンプルコード３です。複数のパイプを使った処理を行ってみます。  
	６つのプロセスを５本のパイプで繋げて、プロセス同士のデータのやり取りをします。コマンドの実行回数は６回です。  
	まず、ベースとなるプロセスの入力元にファイルを繋げます。  
	最初の５回のコマンドは、サンプルコード２のように、子プロセス・親プロセスを使ってデータのやり取りをします。最後の１回のコマンドは、プロセスの出力先にファイルを繋げてから、実行します。これで実行結果をファイルに流せます。  

	実行コマンドはこちらです。  
	```sh
	./p2c3 files/infile.txt files/outfile.txt
	```
	次のコマンドと同じ挙動となります。  
	```sh
	< files/infile.txt grep aa | grep xx | grep yy | grep zz | grep bb | wc -w > files/outfile.txt
	```

