# TIL   / date
  ## Unity
    ### Coroutine < C# >


> Summary
-  
-  
-  
-  

### C#
> Expain shortly

설명


```
public class test : MonoBehaviour {
    public test instance
    {
        get
        {
            if(_instance == null)
            {
                _instance = new test();
            }
            return  _instance;
        }
        set
        {
            _instance = value;
            Number = 1;
        }
    }
    private test _instance = null;
    private int Number = 0;


```

### C#
> Expain shortly

설명


```
Typing Code

```
