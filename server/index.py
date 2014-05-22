import web
import serial
import re
import os

"""
ser = serial.Serial(
    port = '/dev/ttyACM0' ,
    baudrate = 9600 ,
    timeout = 1
)
"""

urls = (
    '/(.*)', 'control'
)
#app = web.application(urls, globals())

t_globals = {
    'datestr': web.datestr
}
render = web.template.render( 'plantillas' , base = 'base' , globals=t_globals )

patron = re.compile('\d+')
MAX = 100
MIN = 0
BASE_DIR = os.path.dirname( os.path.dirname(__file__) )

class control:
    def GET( self  , peticion ):
        return render.index()

    def POST( self , peticion ):
        data = web.input()
        id_p = data.get('id_p')
        if id_p == 'adelante':
            return id_p
        elif id_p == 'atras':
            return id_p
        elif id_p == 'izquierda':
            return id_p
        elif id_p == 'derecha':
            return id_p
        elif id_p == 'c_arriba':
            return id_p
        elif id_p == 'c_abajo':
            return id_p
        elif id_p == 'c_derecha':
            return id_p
        elif id_p == 'c_izquierda':
            return id_p

app = web.application( urls , globals() )
application = app.wsgifunc()
##  deshabilit for ng
if __name__ == "__main__":
    app.run()
