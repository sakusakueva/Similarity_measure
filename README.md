# Similarity measure of template matching 


## 事前準備

自分のローカルに，ソースコードをクローンする．<br>

~~~
$ git clone https://github.com/sakusakueva/Similarity_measure.git
$ cd Similarity_measure
~~~


## 開発手順

### (1) ブランチの作成

プログラムを開発するときは，各自が専用のブランチを作成する．<br>

~~~
$ git branch <branch_name>
$ git checkout <branch_name>
~~~

`<branch_name>`には，自分が開発するブランチを設定する．（ブランチ名は以下を参照）<br>

`develop/hoge`<br>

### (2) プログラムの更新（プッシュ）

ブランチを変更したら，自分が書きたいソースコードに変更を加える．<br>
以下の流れで，変更したソースコードの情報を更新する．<br>
例えば，`README.md`を更新する場合は，`コミットの名前`を`Update README.md`に置き換える．<br>

~~~
$ git add .
$ git commit -m "コミットの名前"
~~~

以下の流れで，ローカルの更新情報をGitHub上に反映させる．<br>

~~~
$ git push origin <branch_name>
~~~

コードを修正するたびに，本節(2)を実行する．<br>

### (3) 後処理

#### 開発者の場合

更新対象のブランチを`main`に戻す．<br>

~~~
$ git checkout main
~~~

開発途中だったローカルのブランチを削除する．<br>

~~~
$ git branch -D <branch_name>
~~~

#### 開発者＆レビュアー共通

ローカルのデータを最新の状態に更新する．<br>
（GitHub上のデータをローカルに落としてくる．）<br>

~~~
$ git pull origin main
~~~

