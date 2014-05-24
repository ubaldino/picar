
var band_take = false;
var img_take
$(document).ready(function() {
    $("button").bind( "click" , function(){
        //console.log( $(this).attr("name") );
        if( $( this ).attr( 'name' ) != "m_push" ){
            $.ajax({
                type: 'POST',
                data: { id_p : $( this ).attr("name") } ,
                beforeSend: function(){ } ,
                success: function( data ){ 
                    console.log( data );

                }
            });
        }
    });

    
    $("button[name='m_push']").bind( "click" , function(){
            $.ajax({
                type: 'POST',
                data: { id_p : $( this ).attr("name") } ,
                beforeSend: function(){ } ,
                success: function( data ){ 
                    $("#m_img").attr( "src" , "/static/photos/" + data )
                    console.log( data );
                    $("#modal_img").modal({
                      escapeClose: true,
                      clickClose: true,
                      showClose: true
                    });
               }
            });
    });

});