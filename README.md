# Asociatyvūs konteineriai

Programa skirta nuskaityti vartotojo failą ir suskaičiuoti, kiek kartų pasikartoja skirtingi žodžiai, atspausdinti cross-reference lentelę, kurioje matytųsi, kuriose teksto eilutėse yra atitinkamas žodis ir išrinkti iš teksto URL adresus bei juos atspausdinti atskirame faile.

## Veikimo principas

Paleidus programą yra prašoma pateikti failą nuskaitymui (numatytasis failas yra `Text.txt`)

```bash
Iveskite failo kelia (numatytasis Text.txt):
```

Šiame faile įklijavau B. Sruogos "Dievų miško" ištrauką su įterptais URL adresais skirtingose teksto vietose. Pridedu ištrauką:

```
Kol Hitleris valdė tiktai Vokietiją – į lagerius kimšo ir naikino savo piliečius, – žuvo jų tenai šimtai tūkstančių, – tikslaus skaičiaus niekas nežino.
Kai jis pradėjo grobti svetimas žemes, Vokietijos piliečiai galėjo kiek lengviau atsidusti: atsirado naujos gausios naikinimo medžiagos.
Lagerių skaičius sparčiai augo.
www.vu.lt
Dachau, Oranienburgas, Buchenvaldas, Mathauzenas, Guzenas, Gros-Rozenas, Ravensbrukas, Flosenburgas, Ausšvicas – svarbesnieji Vokietijos lageriai gyventojų skaičiaus atžvilgiu buvo ištisi miestai su savo filialais ir fabrikais, su savo atskirais įstatymais, su savo nuosava teise ir morale, niekur kitur nepraktikuojama, su savo nuosavomis partijomis ir partinėmis rietenomis, su savo papročiais ir gyvenimiška išmintim.
1943 metų pabaigoj visi Vokietijos koncentracijos lageriai pagal režimo kietumą buvo suskirstyti į penkias kategorijas.
```

Programos veikimo pabaigoje yra sukuriami 3 failai, kurių turinį galite matyti apačioje:

`cross_reference.txt` ištrauka:

```
zodis           1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 
---------------------------------------------------------------------------------------------
baraką            *   *
baroko           * *
buvo           *     *   *           *  *                 *  *  *  *  *  *  *  *
dachau                               *                    *     *
darbo                        *
galėjo          *     *                         *
```

`word_count.txt` ištrauka:

```
zodis           kiekis
--------------------
baraką        2
baroko         2
buvo           14
dachau         3
darbo          2
galėjo        3
```

`urls.txt` turinys:

```
https://www.lrt.lt/
www.hostinger.com
www.vu.lt
```

# Rezultatai
Programa veikia tiksliai bei leidžia ne tik atrasti kokie žodžiai kur buvo panaudoti tekste, bet ir kiek kartu apskritai. 
