javac Main.java
result=$(java Main < a.txt);
answer=$(tail -n 1 a.txt)
[ -f Main.class ] && rm Main.class;
echo 'result: '$result", answer: "$answer 
