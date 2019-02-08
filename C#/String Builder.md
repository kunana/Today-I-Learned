<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [TIL   / 2018-06-01](#til----2018-06-01)
  - [StringBuilder](#stringbuilder)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# TIL   / 2018-06-01
    ## StringBuilder < C# >
## StringBuilder 

```cs
string a = "ABC" + "BFD";
a.Tostring();

//문자열을 합치는 것 보다 빠름.
StringBuilder builder = new StringBuilder();
builder.Append("ABC");
builder.Append("BFD");
builder.Tostring();
```

[공부해서 추가할 부분](http://www.yoda.arachsys.com/csharp/stringbuilder.html)