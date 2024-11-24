# n倍数关系

## 题目描述：

给定若干不完全相同的正整数（数值小于10000）和n（n<5)，计算这些正整数里面有多少数对满足：其中一个是另一个的n倍。例如：1 4 3 2 9 7 18 22，n=3时得到的答案是2；因为3是1的3倍，9是3的3倍。

## 输入：

输入第一行给出正整数n的值，接下来包括多组测试数据。每组数据最多100个整数占用一行，以数字0结束(不计入100个整数里)。测试数据不超过20组，最后一行只包括-1，表示输入数据结束。

## 输出：

对每组输入数据，输出一行，给出有多少数对满足其中一个是另一个n倍；如果没有满足要求的数对，则输出0。

（注：最后一行末尾无换行符等多余字符）。

## 样例：

<pre class=""><div class="code-tool-wrap clearfix"><div class="code-lang fl">Plain Text</div><div class="copy1 fr"><i></i><span></span></div></div><code class="hljs language-diff"><table class="hljs-ln"><tbody><tr><td class="hljs-ln-line hljs-ln-numbers" data-line-number="1"><div class="hljs-ln-n" data-line-number="1"></div></td><td class="hljs-ln-line hljs-ln-code" data-line-number="1">输入：</td></tr><tr><td class="hljs-ln-line hljs-ln-numbers" data-line-number="2"><div class="hljs-ln-n" data-line-number="2"></div></td><td class="hljs-ln-line hljs-ln-code" data-line-number="2">2</td></tr><tr><td class="hljs-ln-line hljs-ln-numbers" data-line-number="3"><div class="hljs-ln-n" data-line-number="3"></div></td><td class="hljs-ln-line hljs-ln-code" data-line-number="3">1 4 3 2 9 7 18 22 0</td></tr><tr><td class="hljs-ln-line hljs-ln-numbers" data-line-number="4"><div class="hljs-ln-n" data-line-number="4"></div></td><td class="hljs-ln-line hljs-ln-code" data-line-number="4">2 4 8 8 0</td></tr><tr><td class="hljs-ln-line hljs-ln-numbers" data-line-number="5"><div class="hljs-ln-n" data-line-number="5"></div></td><td class="hljs-ln-line hljs-ln-code" data-line-number="5">7 5 11 13 1 3 0</td></tr><tr><td class="hljs-ln-line hljs-ln-numbers" data-line-number="6"><div class="hljs-ln-n" data-line-number="6"></div></td><td class="hljs-ln-line hljs-ln-code" data-line-number="6">-1</td></tr></tbody></table></code></pre>

<pre class="hover"><div class="code-tool-wrap clearfix"><div class="code-lang fl">Plain Text</div><div class="copy1 fr"><i></i><span></span></div></div><code class="hljs language-undefined"><table class="hljs-ln"><tbody><tr><td class="hljs-ln-line hljs-ln-numbers" data-line-number="1"><div class="hljs-ln-n" data-line-number="1"></div></td><td class="hljs-ln-line hljs-ln-code" data-line-number="1">输出：</td></tr><tr><td class="hljs-ln-line hljs-ln-numbers" data-line-number="2"><div class="hljs-ln-n" data-line-number="2"></div></td><td class="hljs-ln-line hljs-ln-code" data-line-number="2">3</td></tr><tr><td class="hljs-ln-line hljs-ln-numbers" data-line-number="3"><div class="hljs-ln-n" data-line-number="3"></div></td><td class="hljs-ln-line hljs-ln-code" data-line-number="3">3</td></tr><tr><td class="hljs-ln-line hljs-ln-numbers" data-line-number="4"><div class="hljs-ln-n" data-line-number="4"></div></td><td class="hljs-ln-line hljs-ln-code" data-line-number="4">0</td></tr></tbody></table></code></pre>
