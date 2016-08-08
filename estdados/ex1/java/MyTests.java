import static org.junit.Assert.*;
import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.Test;
import java.util.*;
import org.junit.*;


public class MyTests {

    @Test
    public  void contaElementosNegativos_teste() {
        ArrayTool tester = new ArrayTool();

        int[] arr;
        arr = new int[] {0, 1, -2, 3, -4};
        int b =0;
        b = tester.contaElementosNegativos(arr);
        assertEquals("contaElementosNegativos({0, 1, -2, 3, -4}) = 2", 2, b);

        arr = new int[] {0, 0, 0, 0};
        b = tester.contaElementosNegativos(arr);
        assertEquals("contaElementosNegativos({0, 0, 0, 0}) = 0", 0, b);

        arr = new int[] {-1, -1, -1, -1, -1, -1};
        b = tester.contaElementosNegativos(arr);
        assertEquals("contaElementosNegativos({-1, -1, -1, -1, -1, -1}) = 6", 6, b);
    }

    @Test
    public  void contaOcorrenciasValor_teste() {
        ArrayTool tester = new ArrayTool();

        int[] arr;
        arr = new int[] {0, 1, -2, 3, -4};
        int b =0;
        b = tester.contaOcorrenciasValor(arr, -2);
        assertEquals("contaOcorrenciasValor({0, 1, -2, 3, -4}, -2) = 1", 1, b);

        arr = new int[] {0, 0, 0, 0};
        b = tester.contaOcorrenciasValor(arr, 0);
        assertEquals("contaOcorrenciasValor({0, 0, 0, 0}, 0) = 4", 4, b);

        arr = new int[] {-1, -1, -1, -1, -1, -1};
        b = tester.contaOcorrenciasValor(arr, -1);
        assertEquals("contaOcorrenciasValor({-1, -1, -1, -1, -1, -1}, -1) = 6", 6, b);
    }

    @Test
    public  void temElementosDistintos_teste() {
        ArrayTool tester = new ArrayTool();

        int[] arr;
        arr = new int[] {0, 1, -2, 3, -4};
        boolean b;
        b = tester.temElementosDistintos(arr);
        assertEquals("temElementosDistintos({0, 1, -2, 3, -4}) = true", true, b);

        arr = new int[] {0, 0, 0, 0};
        b = tester.temElementosDistintos(arr);
        assertEquals("temElementosDistintos({0, 0, 0, 0}) = false", false, b);

        arr = new int[] {-1, -1, -1, -1, -1, -1};
        b = tester.temElementosDistintos(arr);
        assertEquals("temElementosDistintos({-1, -1, -1, -1, -1, -1}) = false", false, b);
    }

    @Test
    public  void retornaPosicaoMaiorElemento_teste() {
        ArrayTool tester = new ArrayTool();

        int[] arr;
        arr = new int[] {0, 1, -2, 3, -4};
        int b;
        b = tester.retornaPosicaoMaiorElemento(arr);
        assertEquals("retornaPosicaoMaiorElemento({0, 1, -2, 3, -4}) = 3", 3, b);

        arr = new int[] {0, 0, 0, 0};
        b = tester.retornaPosicaoMaiorElemento(arr);
        assertEquals("retornaPosicaoMaiorElemento({0, 0, 0, 0}) = 0", 0, b);

        arr = new int[] {-1, -1, -1, -1, -1, -1};
        b = tester.retornaPosicaoMaiorElemento(arr);
        assertEquals("retornaPosicaoMaiorElemento({-1, -1, -1, -1, -1, -1}) = 0", 0, b);
    }
}
