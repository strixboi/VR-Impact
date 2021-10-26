# VR Impact
## Projekt Dawida Bożka

 Projektem, który postaram się w tym semestrze zrealizować będzie gra na platformę VR przygotowana na silniku Unreal Engine 4.
Gra będzie oparta na kilku średniozaawansowanych mechanikach, które opiszę poniżej. Projekt zamierzam przygotować sam,
posiłkując się conajwyżej assetami modeli 3D, których nie będę w stanie sam wykonać ze względu na ich skomplikowanie.

### Wszystkie zmiany będą tutaj najszybciej aktualizowane i będę tutaj prowadził mały dziennik developerski w celu motywacji i uprzedniego dokumentowania zmian
 
## Końcowy produkt 
 VR Impact będzie swoistym rozwinięciem koncepcji gier rouge-like, czyli za każdym razem kiedy rozpoczynamy grę mapa jest pseudolosowo generowana, 
a my będziemy próbować przetrwać zbliżające się hordy przeciwników. Gracz będzie mógł zbierać rozsiane na całej mapie perki podwyższające jego statystyki, oraz 5-6 rodzai broni które będą się sprawdzać różnie w zależności od przeciwnika. Przeciętne podejście do gry chciałbym aby zajmowało do 30 minut, zakładając że gracz zawsze zaczyna z niczym, rośnie w siłę, a na końcu zmierza się z bossem fabularnym. Nie jestem pewien jeszcze pewien odnośnie możliwości implementacji niektorych mechanik, ale jeżeli zdecyduję się je dodać pojawią się w Funkcjonalnościach niżej.
 Moje obawy już teraz stanowi szata graficzna projektu, ponieważ nie pracowałem za dużo nad grafiką 3D ani shaderami, więc w najgorszym wypadku projekt będzie gotowy bez zaawansowanej szaty graficznej.

## Wykorzystam
  - Unreal Engine 4.26
  - Visual Studio
  - Blender
  - FL Studio
  - Clip Studio Paint

## Funkcjonalności i kiedy zamierzam je najpóźniej zaimplementować

- 09.11.2021 (Raport I)
  - Poruszanie postaci w przestrzeni 3D
    - Jest to szczególnie kluczowe podczas projektu, ponieważ w celu wykonania Projektu w C++ postaram się ograniczyć korzystanie z blueprintów oferowanych przez język.
    - Unreal Engine nie oferuje niestety gotowego presetu dla zastosowania VR w C++, dlatego projekt zaczynam nie od zera tylko jeszcze niższego poziomu.
    - Jeżeli do tego czasu nie uda mi się zrobić tego to cały zamysł gry będę musiał przenieść na trzecioosobową kamerę i dopiero z tego trybu przenieść projekt na VR
  - Działanie kamery
    - Oculus CV1 z którego korzystam na codzień i pod który będę pisać cały projekt nie jest aż tak kompatybilny z UE jak bym tego chciał, dlatego będę musiał zaimplementować możliwość konfigurowania wysokości pod danego użytkownika i rozstawu oczu.
  - Chwytanie przedmiotów
  - Kolizje pomiędzy przedmiotami 
- 23.11.2021 (Raport II)
  - Dodanie przedmiotów (perków)
  - Pierwsze 2-3 modele broni, oraz ich działanie
  - Cele treningowe do testowania broni
- 07.12.2021 (Raport III)
  - Działający przeciwnicy ~~z podstawowym AI~~ 
  - Generowanie mapy
  - Ekwipunek
- 21.12.2021 (Raport IV)
  - Z racji, że okres przedświąteczny zmuszony będę spędzić zdala od mojego stanowiska pracy, to część elementów może zostać przeniesiona na prototyp
  - Oteksturyzowanie wszystkich assetów
  - Dodatkowe mechaniki walki
  - Menu główne,opcji etc.
  - Dźwięki
