/* InstantClick 3.1.0 | (C) 2014-2017 Alexandre Dieulot | http://instantclick.io/license
https://www.xinroom.cn/new-instantclick-js */
var instantclick=function(t,e,n){function r(){$("#bar").removeClass("visible")}function i(){$("#bar").addClass("visible")}function o(t){var e=t.indexOf("#")
return-1==e?t:t.substr(0,e)}function a(t){for(;t&&"A"!=t.nodeName;)t=t.parentNode
return t}function l(t){do{if(!t.hasAttribute)break
if(t.hasAttribute("data-instant"))return!1
if(t.hasAttribute("data-no-instant"))return!0}while(t=t.parentNode)
return!1}function s(t){var n=e.protocol+"//"+e.host
return t.target||t.hasAttribute("download")||0!=t.href.indexOf(n+"/")||t.href.indexOf("#")>-1&&o(t.href)==Y||l(t)?!1:!0}function f(t){for(var e=Array.prototype.slice.call(arguments,1),n=!1,r=0;r<at[t].length;r++)if("receive"==t){var i=at[t][r].apply(window,e)
i&&("body"in i&&(e[1]=i.body),"title"in i&&(e[2]=i.title),n=i)}else at[t][r].apply(window,e)
return n}function d(a,l,s,d){if(p(),t.documentElement.replaceChild(l,t.body),t.title=a,s){m("remove"),s!=e.href&&(history.pushState(null,null,s),n.indexOf(" CriOS/")>-1&&(t.title==a?t.title=a+String.fromCharCode(160):t.title=a))
var u=s.indexOf("#"),g=u>-1&&t.getElementById(s.substr(u+1)),y=0
if(g)for(;g.offsetParent;)y+=g.offsetTop,g=g.offsetParent
"requestAnimationFrame"in window?requestAnimationFrame(function(){scrollTo(0,y)}):scrollTo(0,y),v(),Y=o(s),Y in ft&&(ft[Y]=[]),lt[Y]={},b(function(t){return!t.hasAttribute("data-instant-track")}),i(),q(r,100),f("change",!1)}else scrollTo(0,d),X.abort(),c(),b(function(t){return t.hasAttribute("data-instant-restore")}),h(),f("restore")}function c(){nt=!1,rt=!1}function u(t){return t.replace(/<noscript[\s\S]+?<\/noscript>/gi,"")}function p(){for(var t=0;t<st.length;t++)"object"==typeof st[t]&&"abort"in st[t]&&(st[t].instantclickAbort=!0,st[t].abort())
st=[]}function v(){for(var t in lt[Y]){var e=lt[Y][t]
window.clearTimeout(e.realId),e.delayLeft=e.delay-+new Date+e.timestamp}}function h(){for(var t in lt[Y])if("delayLeft"in lt[Y][t]){for(var e=[lt[Y][t].callback,lt[Y][t].delayLeft],n=0;n<lt[Y][t].params.length;n++)e.push(lt[Y][t].params[n])
w(e,lt[Y][t].isRepeating,lt[Y][t].delay),delete lt[Y][t]}}function g(){X.abort(),c()}function m(t){if(Y in ft)for(var e=0;e<ft[Y].length;e++)window[t+"EventListener"].apply(window,ft[Y][e])}function b(e){var n,r,i,o,a,l=t.body.getElementsByTagName("script"),s=[]
for(a=0;a<l.length;a++)s.push(l[a])
for(a=0;a<s.length;a++)if(n=s[a],n&&e(n)){r=t.createElement("script")
for(var f=0;f<n.attributes.length;f++)r.setAttribute(n.attributes[f].name,n.attributes[f].value)
r.textContent=n.textContent,i=n.parentNode,o=n.nextSibling,i.removeChild(n),i.insertBefore(r,o)}}function y(){for(var e,n,r=t.querySelectorAll("[data-instant-track]"),i=0;i<r.length;i++)e=r[i],n=e.getAttribute("href")||e.getAttribute("src")||e.textContent,ot.push(n)}function w(t,e,n){var r=t[0],i=t[1],o=[].slice.call(t,2),a=+new Date
Q++
var l,s=Q
l=e?function(e){r(e),delete lt[Y][s],t[0]=r,t[1]=i,w(t,!0)}:function(t){r(t),delete lt[Y][s]},t[0]=l,void 0!=n&&(a+=i-n,i=n)
var f=window.setTimeout.apply(window,t)
return lt[Y][s]={realId:f,timestamp:a,callback:r,delay:i,params:o,isRepeating:e},-s}function E(t){var e=a(t.target)
e&&s(e)&&C(e.href)}function x(t){G=+new Date
var e=a(t.target)
e&&s(e)&&(W&&(N(W),W=!1),e.addEventListener("touchend",k),e.addEventListener("touchcancel",k),C(e.href))}function A(){t.addEventListener("click",L)}function L(e){if(t.removeEventListener("click",L),W&&(N(W),W=!1),!e.defaultPrevented){var n=a(e.target)
n&&s(n)&&(0!=e.button||e.metaKey||e.ctrlKey||(e.preventDefault(),T(n.href)))}}function k(t){nt&&!rt&&(W=q(g,500))}function P(){if(2==X.readyState){var n=X.getResponseHeader("Content-Type")
n&&/^text\/html/i.test(n)||(z=!0)}if(!(X.readyState<4)){if(0==X.status)return it=!0,void(rt&&(f("exit",Z,"network error"),e.href=Z))
if(z)return void(rt&&(f("exit",Z,"non-html"),e.href=Z))
var r=t.implementation.createHTMLDocument("")
r.documentElement.innerHTML=u(X.responseText),_=r.title,tt=r.body
var i=f("receive",Z,tt,_)
i&&("body"in i&&(tt=i.body),"title"in i&&(_=i.title))
var a=o(Z)
V[a]={body:tt,title:_,scrollPosition:a in V?V[a].scrollPosition:0}
var l,s,d=r.querySelectorAll("[data-instant-track]")
if(d.length!=ot.length)J=!0
else for(var c=0;c<d.length;c++)l=d[c],s=l.getAttribute("href")||l.getAttribute("src")||l.textContent,-1==ot.indexOf(s)&&(J=!0)
rt&&(rt=!1,T(Z))}}function S(){var t=o(e.href)
if(t!=Y){if(rt&&(c(),X.abort()),!(t in V))return f("exit",e.href,"not in history"),void(t==e.href?e.href=e.href:e.reload())
V[Y].scrollPosition=pageYOffset,v(),m("remove"),Y=t,d(V[t].title,V[t].body,!1,V[t].scrollPosition),m("add")}}function C(t){j&&(N(j),j=!1),t||(t=K),(!nt||t!=Z&&!rt)&&(nt=!0,rt=!1,Z=t,tt=!1,z=!1,it=!1,J=!1,f("preload"),X.open("GET",t),X.timeout=9e4,X.send())}function T(t){return et=+new Date,j||!nt?j&&Z&&Z!=t?(f("exit",t,"click occured"),void(e.href=t)):(C(t),f("wait"),void(rt=!0)):rt?(f("exit",t,"waiting for completion"),void(e.href=t)):z?(f("exit",Z,"non-html"),void(e.href=Z)):it?(f("exit",Z,"network error"),void(e.href=Z)):J?(f("exit",Z,"different assets"),void(e.href=Z)):tt?(V[Y].scrollPosition=pageYOffset,c(),void d(_,tt,Z)):(f("wait"),i(),q(r,150),void(rt=!0))}function O(){return ct?void(U||(U=!0,Y=o(e.href),lt[Y]={},V[Y]={body:t.body,title:t.title,scrollPosition:pageYOffset},"loading"==t.readyState?t.addEventListener("DOMContentLoaded",y):y(),X=new XMLHttpRequest,X.addEventListener("readystatechange",P),t.addEventListener("touchstart",x,!0),t.addEventListener("mousedown",E,!0),t.addEventListener("click",A,!0),addEventListener("popstate",S))):void f("change",!0)}function D(t,e){at[t].push(e),"change"==t&&e(!et)}function q(){return w(arguments,!1)}function M(){return w(arguments,!0)}function N(t){t=-t
for(var e in lt)t in lt[e]&&(window.clearTimeout(lt[e][t].realId),delete lt[e][t])}function I(t){st.push(t)}function B(){Y in ft||(ft[Y]=[]),ft[Y].push(arguments),addEventListener.apply(window,arguments)}function F(){if(Y in ft)t:for(var t=0;t<ft[Y].length;t++)if(arguments.length==ft[Y][t].length){for(var e=0;e<ft[Y][t].length;e++)if(arguments[e]!=ft[Y][t][e])continue t
ft[Y].splice(t,1)}}function H(e,r,i){if(!(r in dt)&&(dt[r]={},t.addEventListener(r,function(t){var e=t.target
for(t.originalStopPropagation=t.stopPropagation,t.stopPropagation=function(){this.isPropagationStopped=!0,this.originalStopPropagation()};e&&1==e.nodeType;){for(var n in dt[r])if(e.matches(n)){for(var i=0;i<dt[r][n].length;i++)dt[r][n][i].call(e,t)
if(t.isPropagationStopped)return
break}e=e.parentNode}},!1),"click"==r&&/iP(?:hone|ad|od)/.test(n))){var o=t.createElement("style")
o.setAttribute("instantclick-mobile-safari-cursor",""),o.textContent="body{cursor:pointer!important}",t.head.appendChild(o)}e in dt[r]||(dt[r][e]=[]),R(e,r,i),dt[r][e].push(i)}function R(t,e,n){var r=dt[e][t].indexOf(n)
r>-1&&dt[e][t].splice(r,1)}var Y,K,j,G,U,W,X,z,J,Q=0,V={},Z=!1,_=!1,tt=!1,et=0,nt=!1,rt=!1,it=!1,ot=[],at={preload:[],receive:[],wait:[],change:[],restore:[],exit:[]},lt={},st=[],ft={},dt={}
Element.prototype.matches||(Element.prototype.matches=Element.prototype.webkitMatchesSelector||Element.prototype.msMatchesSelector||function(e){for(var n=t.querySelectorAll(e),r=0;r<n.length;r++)if(n[r]==this)return!0
return!1})
var ct=!1
if("pushState"in history&&"file:"!=e.protocol){ct=!0
var ut=n.indexOf("Android ")
if(ut>-1){var pt=parseFloat(n.substr(ut+8))
if(4.4>pt&&(ct=!1,pt>=4))for(var vt=[/ Chrome\//,/ UCBrowser\//,/ Firefox\//,/ Windows Phone /],ht=0;ht<vt.length;ht++)if(vt[ht].test(n)){ct=!0
break}}}return{supported:ct,init:O,on:D,setTimeout:q,setInterval:M,clearTimeout:N,xhr:I,addPageEvent:B,removePageEvent:F,addEvent:H,removeEvent:R}}(document,location,navigator.userAgent)
/*百度统计*自行替换hm*/
var _hmt=_hmt || [];(function(){var hm=document.createElement("script");hm.src="//hm.baidu.com/hm.js?be30ae751487acd59bdfa0a2634aae46";var s=document.getElementsByTagName("script")[0];s.parentNode.insertBefore(hm,s);})()
/*end*/
instantclick.on('change', function () {/*需要执行的js语句*/
 _hmt.push(["_trackPageview", location.pathname + location.search])  //百度统计
}), instantclick.init()