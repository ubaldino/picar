
var band_take = false;
var img_take
$(document).ready(function() {
    $("button").bind( "click" , function(){
        //console.log( $(this).attr("name") );

        if( $( this ).attr( 'name' ) != "m_push" ){
        
            if ( $( this ).attr( 'name' )  == "temp_btn" ) {
                   
                $.ajax({
                    type: 'POST',
                    data: { id_p : $( this ).attr("name") } ,
                    beforeSend: function(){ } ,
                    success: function( data ){ 
                        console.log( data );
                        bootbox.dialog({
                            message: 'Tempertura: '+data.split(":")[0]+'<br/>Humedad: '+data.split(":")[1] ,
                            title: "Temperatura/Humedad",
                            onEscape: function() {},
                            show: true,

                            backdrop: false,
                            closeButton: false,
                            animate: false,

                            className: "temp-modal",

                        });

                        setTimeout(function(){
                            bootbox.hideAll()
                        }, 2000 ); 
                    }
                });

            }
            else if ( $( this ).attr( 'name' )  == "s_medir" ) {

                        bootbox.dialog({
                            message: 'Distancia: '+160+ ' [cm]',
                            title: "Distancia",
                            onEscape: function() {},
                            show: true,
                  
                            backdrop: false,
                            closeButton: false,
                            animate: false,
                  
                            className: "distancia-modal",
                  
                        });


                /*
                $.ajax({
                    type: 'POST',
                    data: { id_p : $( this ).attr("name") } ,
                    beforeSend: function(){ } ,
                    success: function( data ){ 
                        console.log( data );
                        bootbox.dialog({
                  			message: 'Distancia: '+data+ ' [cm]',
                            title: "Distancia",
                  			onEscape: function() {},
                  			show: true,
                  
                  			backdrop: false,
                  			closeButton: false,
                  			animate: false,
                  
                  			className: "distancia-modal",
                  
                		});

                		setTimeout(function(){
                    		bootbox.hideAll()
                		}, 2000 ); 
                    }
                });
                */

            }
            else if ( $( this ).attr( 'name' )  == "exo_btn" ) {

                $.ajax({
                    type: 'POST',
                    data: { id_p : $( this ).attr("name") } ,
                    beforeSend: function(){ } ,
                    success: function( data ){ 
                        console.log( data );
                        bootbox.dialog({
                            message: 'Modo: '+data,
                            title: "Modo",
                            onEscape: function() {},
                            show: true,
                  
                            backdrop: false,
                            closeButton: false,
                            animate: false,
                  
                            className: "modo-modal",
                  
                        });

                        setTimeout(function(){
                            bootbox.hideAll()
                        }, 2000 ); 
                    }
                });

            }
            else{


                console.log($( this ).attr( 'name' ) );
                    $.ajax({
                        type: 'POST',
                        data: { id_p : $( this ).attr("name") } ,
                        beforeSend: function(){ } ,
                        success: function( data ){ 
                            console.log( data );

                        }
                    });

            }
        }      
    });




    
    $("button[name='m_push']").bind( "click" , function(){
            
            $.ajax({
                type: 'POST',
                data: { id_p : $( this ).attr("name") } ,
                beforeSend: function(){ } ,
                success: function( data ){ 
                    //$("#m_img").attr( "src" , "/static/photos/" + data )
                    console.log( data );
                    
                    bootbox.dialog({
                      message: '<img  src="/static/photos/'+data+'" width="800px"/>',
                      title: "Captura de microscopio",
                      onEscape: function() {},
                      show: true,
                      
                      backdrop: false,
                      closeButton: false,
                      animate: false,
                      className: "my-modal",
                    });
                    
                }
            });
            

    });

});
