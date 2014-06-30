
var band_take = false;
var img_take
$(document).ready(function() {
    $("button").bind( "click" , function(){
        //console.log( $(this).attr("name") );

        


    if( $( this ).attr( 'name' ) != "m_push" ){
        
        if ( $( this ).attr( 'name' )  == "temp_btn" ) {
            bootbox.dialog({
              message: 'Tempertura: 24 ªC',
              title: "Temperatura",
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
        else if ( $( this ).attr( 'name' )  == "s_medir" ) {
            bootbox.alert( "Distancia" );    
        }
        else if ( $( this ).attr( 'name' )  == "exo_btn" ) {
            bootbox.alert( "cambio de modo" );    
        }
        else{


            console.log($( this ).attr( 'name' ) );
            /*
                $.ajax({
                    type: 'POST',
                    data: { id_p : $( this ).attr("name") } ,
                    beforeSend: function(){ } ,
                    success: function( data ){ 
                        console.log( data );

                    }
                });
            */



            }
        }      
    });




    
    $("button[name='m_push']").bind( "click" , function(){
            bootbox.dialog({
              message: '<img  src="/static/photos/20140524213617.jpg" width="800px"/>',
              title: "Captura de microscopio",
              onEscape: function() {},
              show: true,
              
              backdrop: false,
              closeButton: false,
              animate: false,
              
              className: "my-modal",
              
              /*buttons: {
                success: {   
                  label: "Success!",
                  className: "btn-success",
                  
                  callback: function() {}
                },
                "Danger!": {
                  className: "btn-danger",
                  callback: function() {}
                },
                
                "Another label": function() {}
              }
              */
            });

            /*
            $.ajax({
                type: 'POST',
                data: { id_p : $( this ).attr("name") } ,
                beforeSend: function(){ } ,
                success: function( data ){ 
                    //$("#m_img").attr( "src" , "/static/photos/" + data )
                    console.log( data );
                    Modal.open({
                        content: '<img id="m_img" src="/static/photos/20140524213934.jpg" alt="">',
                        width: '70%', // Can be set to px, em, %, or whatever else is out there.
                        height: '70%',
                        hideclose: true, // Hides the close-modal graphic
                        closeAfter: 10 // Define this number in seconds.
                    });
                }
            });
            */
    });

});
